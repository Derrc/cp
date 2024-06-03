#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
  Greedy: same concept as scheduling problem where we process movies in order of earliest end times (optimal apprroach)
  - keep track of k students that are assigned the next available movie
  - for next movie's start time, assign it to student with latest end time for their current movie: max(si) <= m_start
*/

bool cmp(const pair<int, int> &t1, const pair<int, int> &t2) {
  return t1.second < t2.second;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> times(n);
  for (int i = 0; i < n; i++) {
    cin >> times[i].first >> times[i].second;
  }

  multiset<int> end_times;
  for (int i = 0; i < k; i++) {
    end_times.insert(0);
  }

  sort(times.begin(), times.end(), cmp);

  int movies = 0;

  for (int i = 0; i < n; i++) {
    // see which student can watch current movie (start time)
    auto next = end_times.upper_bound(times[i].first);
    // all student end times are greater than current movie start time, no one can watch the movie
    if (next == end_times.begin()) { continue; }

    end_times.erase(--next);
    end_times.insert(times[i].second);
    movies += 1;
  }

  cout << movies;
}
