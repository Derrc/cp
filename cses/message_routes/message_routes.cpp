#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
  Shortest path in unweighted graph using BFS
  - backtrack using parent array
  - keep track of visited and level of each node using distance array
*/

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int start, end;
    cin >> start >> end;
    adj[--start].push_back(--end);
    adj[end].push_back(start);
  }

  vector<int> distance(n, INT32_MAX);
  distance[0] = 0;
  vector<int> parent(n);
  deque<int> q = {0};

  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    for (int neighbor : adj[cur]) {
      if (distance[neighbor] != INT32_MAX) { continue; }

      // update distance and parent of neighbor node
      distance[neighbor] = distance[cur]+1;
      parent[neighbor] = cur;
      q.push_back(neighbor);
    }
  }

  if (distance[n-1] != INT32_MAX) {
    // print number of nodes in route (not length of route)
    cout << distance[n-1]+1 << "\n";
    // backtrack using parents
    vector<int> path = {n-1};
    while (path.back() != 0) {
      path.push_back(parent[path.back()]);
    }

    for (int i = path.size()-1; i >= 0; i--) {
      cout << path[i]+1 << " ";
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}