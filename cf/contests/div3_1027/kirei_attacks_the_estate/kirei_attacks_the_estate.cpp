#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// Max threat of vertex v = max(danger(v), danger(v) - min threat of parent(v))
// Min threat of vertex v = min(danger(v), danger(v) - max threat of parent(v))
// Can be calculated recursively with DFS
// Subtracting threat of parent vertex maintains alternating parity

vector<ll> d;
vector<ll> t;
vector<vector<int>> adj;

void dfs(int cur, int prev, ll minT, ll maxT) {
  t[cur] = max(d[cur], d[cur] - minT);
  minT = min(d[cur], d[cur] - maxT);

  for (int next : adj[cur]) {
    if (next != prev) {
      dfs(next, cur, minT, t[cur]);
    }
  }
}

void solve() {
  int n;
  cin >> n;

  d.resize(n);
  t.resize(n);
  adj.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  dfs(0, -1, 0, 0);

  for (int i = 0; i < n; i++) {
    cout << t[i] << " ";
  }
  cout << "\n";

  d.clear();
  t.clear();
  adj.clear();
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}