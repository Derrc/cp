#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> cat;
int total;

void dfs(int cur, int prev, int curCats) {
  if (curCats > m) {
    return;
  }

  int isLeaf = 1;
  for (int next : adj[cur]) {
    if (next == prev) { continue; }

    isLeaf = 0;
    dfs(next, cur, cat[next] * (curCats + 1));
  }

  total += isLeaf;
}

int main() {
  cin >> n >> m;

  adj.resize(n);
  cat.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> cat[i];
  }

  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  dfs(0, -1, cat[0]);
  cout << total << "\n";
}