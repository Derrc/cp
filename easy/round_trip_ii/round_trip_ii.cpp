#include <iostream>
#include <vector>
using namespace std;

/*
  Finding cycle in directed graph
  - extension to dfs topo sort
*/

vector<vector<int>> adj;
vector<int> visited, parent;
vector<int> cycle;

void dfs(int node) {
  for (int next : adj[node]) {
    if (parent[next] != -1) {
      // found cycle, backtrack
      cycle.push_back(next);
      int cur = node;
      while (cur != next) {
        cycle.push_back(cur);
        cur = parent[cur];
      }
      cycle.push_back(next);
      return;
    }
    if (visited[next]) { continue; }
    visited[next] = 1;
    parent[next] = node;
    dfs(next);
    parent[next] = -1;

    // early stop if we found cycle
    if (!cycle.empty()) { return; }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  adj.resize(n);
  visited.resize(n);
  parent.resize(n, -1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
  }

  for (int i = 0; i < n; i++) {
    if (!cycle.empty()) { break; }
    dfs(i);
  }

  if (!cycle.empty()) {
    cout << cycle.size() << "\n";
    for (int i = cycle.size()-1; i >= 0; i--) {
      cout << cycle[i]+1 << " ";
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}