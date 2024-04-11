#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
  Combinatorics:
  - brute force: iterate over all possible subsets and calculate number of connected regions O(NlogN * 2^N) by sorting and counting overlapping intervals
  - optimized: count how many subsets each segment contributes to the total complexity O(N) by keeping track of how many segments are open
*/

const ll MOD = 1e9 + 7;

int n;

void brute_force() {
  vector<pair<int, int>> segments;
  segments.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> segments[i].first >> segments[i].second;
    }

    sort(segments.begin(), segments.end());

    int components = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      int prev_end = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          components += segments[i].first > prev_end;
          prev_end = max(prev_end, segments[i].second);
        }
      }
    }

    cout << components << endl;
}

int main() {
  freopen("help.in", "r", stdin);
  freopen("help.out", "w", stdout);

  cin >> n;

  // keep track of how many segments are open at points[i]
  vector<int> points(2 * n + 1);
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    points[start]++;
    points[end]--;
  }

  // precompute powers of 2
  vector<ll> pow(n + 1);
  pow[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow[i] = 2 * pow[i-1] % MOD;
  }

  ll components = 0;
  int open = 0;
  for (int i = 1; i <= 2 * n; i++) {
    open += points[i];
    // check if new segment opens
    if (points[i] == 1) {
      // calculate how much it adds to complexity
      // 2 ^ open: don't include subsets with open segments since they have been already counted previously, current segment is fixed as part of subset
      components = (components + pow[n - open]) % MOD;
    }
  }

  cout << components << endl;
}