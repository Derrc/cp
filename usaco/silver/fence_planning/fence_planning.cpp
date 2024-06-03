#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> position(n);
  for (int i = 0; i < n; i++) {
    cin >> position[i].first >> position[i].second;
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int c1, c2;
    cin >> c1 >> c2;
    adj[--c1].push_back(--c2);
    adj[c2].push_back(c1);
  }

  vector<bool> visited(n);
  deque<int> q;
  int min_perimeter = INT32_MAX;
  for (int c = 0; c < n; c++) {
    if (visited[c]) { continue; }
    // keep track of min and max for current connected component
    pair<int, int> x = {INT32_MAX, 0};
    pair<int, int> y = {INT32_MAX, 0};

    q.push_back(c);
    visited[c] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();

      // update min and max
      x.first = min(x.first, position[cur].first);
      x.second = max(x.second, position[cur].first);
      y.first = min(y.first, position[cur].second);
      y.second = max(y.second, position[cur].second);

      for (int neighbor : adj[cur]) {
        if (visited[neighbor]) { continue; }

        visited[neighbor] = true;
        q.push_back(neighbor);
      }
    }

    min_perimeter = min(min_perimeter, 2 * (x.second - x.first) + 2 * (y.second - y.first));
  }

  cout << min_perimeter;
}