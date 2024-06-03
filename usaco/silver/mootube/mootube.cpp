#include <iostream>
#include <vector>
using namespace std;

/*
  Tree traversal DFS, O(N+Q)
  - we know graph is a tree since there are n nodes, n-1 edges (connected), 1 simple path b/w all pairs of nodes (acyclic)
*/

// adjacency list but values are of (end, weight)
vector<vector<pair<int, int>>> adj;
int k;

int dfs(int node, int prev) {
  int res = 0;
  for (pair<int, int> child : adj[node]) {
    if (child.first == prev) { continue; }

    // only continue tree path if relevance satisfies k
    // else all nodes past current node in path will be invalid
    if (child.second >= k) {
      res += 1 + dfs(child.first, node);
    }
  }

  return res;
}

int main() {
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  adj.resize(n);

  for (int i = 0; i < n-1; i++) {
    int p, q, r;
    cin >> p >> q >> r;
    adj[--p].push_back({--q, r});
    adj[q].push_back({p, r});
  }

  for (int i = 0; i < q; i++) {
    int start;
    cin >> k >> start;

    cout << dfs(--start, -1) << "\n";
  }
}