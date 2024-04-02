#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
  Greedy: process task with smallest duration next
  - for two consecutive tasks, processing lower duration task first is optimal
  - after both tasks you end up at same time but lower duration task will give more reward since you ended at an earlier time
*/

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> tasks(n);

  for (int i = 0; i < n; i++) {
    cin >> tasks[i].first >> tasks[i].second;
  }

  sort(tasks.begin(), tasks.end());

  ll reward = 0;
  ll time = 0;
  for (int i = 0; i < n; i++) {
    time += (ll)tasks[i].first;
    reward += (ll)tasks[i].second - time;
  }

  cout << reward;
}