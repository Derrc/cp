#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
  Graph traversal: counting nodes in connected components
*/

struct Cow {
  int x, y, p;
};

vector<bool> visited;
vector<vector<int>> adj;

int distance(int x1, int y1, int x2, int y2) {
  return (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
}

// int dfs(int cow) {
//   if (visited[cow]) { return 0; }

//   int reached = 1;
//   visited[cow] = true;
//   for (int neighbor : adj[cow]) {
//     reached += dfs(neighbor);
//   }

//   return reached;
// }

int main() {
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);

  int n;
  cin >> n;

  adj.resize(n);
  visited.resize(n);

  vector<Cow> cows(n);
  for (int i = 0; i < n; i++) {
    cin >> cows[i].x >> cows[i].y >> cows[i].p;
  }

  for (int c1 = 0; c1 < n; c1++) {
    for (int c2 = c1+1; c2 < n; c2++) {
      if (c1 == c2) { continue; }

      auto [x1, y1, p1] = cows[c1];
      auto [x2, y2, p2] = cows[c2];

      int dist = distance(x1, y1, x2, y2);

      if (dist <= p1 * p1) {
        adj[c1].push_back(c2);
      }
      if (dist <= p2 * p2) {
        adj[c2].push_back(c1);
      }
    }
  }
  
  int max_reached = 1;
  
  for (int c = 0; c < n; c++) {
    int reached = 1;
    visited.assign(n, false);
    deque<int> q{c};
    visited[c] = true;

    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();

      for (int neighbor : adj[cur]) {
        if (visited[neighbor]) { continue; }

        q.push_back(neighbor);
        visited[neighbor] = true;
        reached++;
      }
    }

    max_reached = max(max_reached, reached);
  }

  cout << max_reached;
}