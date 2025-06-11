#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

// Find contribution for each edge, since for each edge (u, v), the subtree sum rooted at v must travel along the edge
// to be annihilated.

int const maxN = 1e5 + 5;

ll x[maxN]{};
vector<pii> adj[maxN];
ll res = 0;

void dfs(int cur, int prev) {
  for (auto [nxt, w] : adj[cur]) {
    if (nxt != prev) {
      dfs(nxt, cur);
      // add contribution for edge
      res += w * abs(x[nxt]);
      // x[cur] holds sum of subtree
      x[cur] += x[nxt];
    }
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  for (int i = 0; i < n-1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[--u].push_back({--v, w});
    adj[v].push_back({u, w});
  }

  dfs(0, -1);
  cout << res << endl;
}