#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  DFS
  - find bridges in graph with Tarjan's Algorithm using the DFS tree
  - consider dfs subtree of a vertex, a bridge exists if the subtree does not traverse to an ancestor vertex oustide of subtree
  - no vertex in subtree should have back edge to an ancestor outside of subtree
*/

const ll INF = 1e18 + 5;

int n, m;
vector<vector<int>> adj;
// h[i] = height of vertex i
// sz[i] = sz of subtree from vertex i
// dp[i] = min reachable height in dfs tree from vertex i
vector<ll> h, sz, dp;
vector<bool> vis;
vector<int> bridge;

void dfs(int u) {
  vis[u] = true;
  sz[u] = 1;

  for (int v : adj[u]) {
    if (vis[v]) {
      // v is parent (tree edge)
      // dfs tree has no cross edges (guarenteed to be parent)
      if (h[u] - 1 == h[v]) continue;

      // v is back edge outside of subtree or visited vertex within subtree
      dp[u] = min(dp[u], h[v]);
    } else {
      h[v] = h[u] + 1;
      dfs(v);
      sz[u] += sz[v];
      // check if subtree of v has a back edge outside of u
      dp[u] = min(dp[u], dp[v]);
    }
  }

  // (p(u), u) is a bridge
  if (dp[u] >= h[u]) {
    bridge.push_back(u);
  }
}


int main() {
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    adj.resize(n);
    h.resize(n);
    sz.resize(n);
    dp.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      h[i] = -1;
      sz[i] = 0;
      dp[i] = INF;
      vis[i] = false;
    }

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[--u].push_back(--v);
      adj[v].push_back(u);
    }

    ll res = INF;
    
    bridge.clear();
    h[0] = 0;
    dfs(0);

    for (int u : bridge) {
      ll sz_v = sz[0] - sz[u];
      res = min(res, (sz[u] - 1) * sz[u] / 2 + (sz_v - 1) * sz_v / 2);
    }

    cout << res << "\n";
  }
}