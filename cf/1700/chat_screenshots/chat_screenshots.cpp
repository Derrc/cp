#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Create a directed graph using the screenshots (minus the first node since that provides no info)
// We just need to check if the graph is acyclic or not (topological sorting exists)

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
bool vis[maxN];
bool path[maxN];
bool cycle = false;

void dfs(int cur) {
  vis[cur] = true;
  path[cur] = true;
  for (int nxt : adj[cur]) {
    if (path[nxt]) {
      cycle = true;
      break;
    }
    else if (!vis[nxt]) {
      dfs(nxt);
    }
  }
  path[cur] = false;
}

void solve() {
  int n, k;
  cin >> n >> k;

  fill(begin(adj), end(adj), vector<int>());
  memset(vis, false, sizeof(vis));
  memset(path, false, sizeof(path));
  cycle = false;

  for (int i = 0; i < k; i++) {
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
      cin >> order[i];
    }
    for (int i = 1; i < n-1; i++) {
      int n1 = order[i], n2 = order[i+1];
      adj[--n1].push_back(--n2);
    }
  }

  if (n <= 2) {
    cout << "YES" << "\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  if (cycle) {
    cout << "NO" << "\n";
  } else {
    cout << "YES" << "\n";
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}