#include <iostream>
#include <vector>
#include <string>
using namespace std;
using pii = pair<int, int>;

// If the graph not bipartite -> solution can't exist
// Otherwise 2-color the graph and have all edges point from 1 color set to the other

vector<vector<int>> adj;
vector<int> color;
vector<pii> edges;

bool dfs(int cur, int c) {
  color[cur] = c;
  for (int next : adj[cur]) {
    if (color[next] == -1) {
      if (!dfs(next, c ^ 1)) {
        return false;
      }
    } else {
      if (color[next] == c) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  adj.resize(n);
  color.resize(n, -1);
  edges.resize(m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[--u].push_back({--v});
    adj[v].push_back({u});
    edges[i] = {u, v};
  }

  if (!dfs(0, 0)) {
    cout << "NO" << endl;
    exit(0);
  }
  cout << "YES" << "\n";

  for (auto &[u, v] : edges) {
    // all edges will go from a 1-node -> 0-node
    cout << (color[u] < color[v]);
  }
  cout << endl;
}