#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

vector<vector<pii>> adj;
int maxCost = 0;

void dfs(int cur, int prev, int curCost) {
  int isLeaf = 1;
  for (auto [next, cost] : adj[cur]) {
    if (next != prev) {
      isLeaf = 0;
      dfs(next, cur, curCost + cost);
    }
  }
  if (isLeaf) {
    maxCost = max(maxCost, curCost);
  }
}

int main() {
  int n;
  cin >> n;

  adj.resize(n);
  for (int i = 0; i < n-1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(0, -1, 0);

  cout << maxCost << endl;
}