#include <iostream>
#include <vector>
using namespace std;

/*
  Bitmask DP: O(2^N * N * logC)
  - another method (not implemented): preprocessing O(N^2 * C) where next[i][j][k] = largest show time for j that is <= duration of movie[i] + showtime k for movie[i]
*/

struct Movie {
  int d;
  vector<int> showtimes;
};

struct State {
  int end, m;
};

// binary search, return largest arr[i] that is less than or equal to target
int bs(vector<int> &arr, int target) {
  int lo = -1, hi = arr.size()-1;
  while (lo < hi) {
    int mid = lo + (hi-lo+1)/2;
    if (arr[mid] > target) {
      hi = mid-1;
    } else {
      lo = mid;
    }
  }

  // returns -1 if all arr[i] > target and arr[-1] if all arr[i] <= target
  return lo;
}

int main() {
  freopen("movie.in", "r", stdin);
  freopen("movie.out", "w", stdout);

  int n, l;
  cin >> n >> l;
  
  vector<Movie> movies(n);
  for (int i = 0; i < n; i++) {
    int ntimes;
    cin >> movies[i].d >> ntimes;

    for (int j = 0; j < ntimes; j++) {
      int next;
      cin >> next;
      movies[i].showtimes.push_back(next);
    }
  }

  // dp[i]: {end, min # of movies}] = end of cur movie, # of movies (# of bits)
  vector<State> dp(1<<n);
  int best = n+1;

  for (int s = 1; s < (1<<n); s++) {
    dp[s] = {-1, 0};
    for (int i = 0; i < n; i++) {
      if ((s & (1<<i)) == 0 || dp[s^(1<<i)].end == -1) { continue; }

      State prev = dp[s^(1<<i)];
      // choose latest start time that is <= end of cur movie
      int next = bs(movies[i].showtimes, prev.end);
      // if start time is not valid or is less than current endtime skip
      if (next == -1 || movies[i].showtimes[next] + movies[i].d <= prev.end) {
        continue;
      }

      // update new end time
      dp[s].end = max(dp[s].end, movies[i].showtimes[next]+movies[i].d);
      dp[s].m = prev.m + 1;
    }
    
    if (dp[s].end >= l) {
      best = min(best, dp[s].m);
    }
  }

  cout << (best == n+1 ? -1 : best) << endl;
}