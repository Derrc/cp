#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Each special tree can only have max 2 leaf nodes
// Case with 1 leaf node -> subtree sums are strictly increasing -> 2^n ways
// Case with 2 leaf nodes
// - LCA to root -> 2^(d_lca + 1)
// - d_x = d_y -> 2 * 2^(d_lca + 1) (since either leaf can be assigned 1 or 2 and rest of branches must be assigned 2)
// - d_x < d_y -> (2^(d_y - d_x) + 2^(d_y - d_x - 1)) * 2^(d_lca + 1)

ll const maxN = 2e5 + 5;
ll const mod = 1e9 + 7;

ll pw[maxN];
vector<int> adj[maxN];
vector<int> depth;
ll lca = -1;

void dfs(int cur, int prev, int d) {
  if (adj[cur].size() > 2 || (cur == 0 && adj[cur].size() == 2)) {
    lca = d;
  }

  bool leaf = true;
  for (int nxt : adj[cur]) {
    if (nxt != prev) {
      leaf = false;
      dfs(nxt, cur, d + 1);
    }
  }
  if (leaf) {
    depth.push_back(d);
  }
}

void solve() {
  int n;
  cin >> n;

  fill(begin(adj), end(adj), vector<int>());
  depth.clear();
  lca = -1;

  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  dfs(0, -1, 0);

  if (depth.size() > 2) {
    cout << 0 << "\n";
    return;
  }
  if (depth.size() == 1) {
    cout << pw[n] << "\n";
    return;
  }

  ll diff = abs(depth[0] - depth[1]);
  if (diff == 0) {
    cout << pw[lca + 2] << "\n";
  } else {
    cout << ((pw[lca + 1] * pw[diff] % mod) + (pw[lca + 1] * pw[diff-1] % mod)) % mod << "\n";
  }
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < maxN; i++) {
    pw[i] = 2 * pw[i-1] % mod;
  }

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}