#include <iostream>
#include <vector>
using namespace std;

/*
  DFS on tree
*/

int st;
vector<vector<int>> adj;
vector<int> pos;

// winning pos = 1, losing pos = 0
// pos is wrt to next player, pos[st] holds answer
int dfs(int cur, int prev) {
  if (adj[cur].size() == 1 && adj[cur][0] == prev) {
    return 0;
  }

  for (int nxt : adj[cur]) {
    if (nxt == prev) { continue; }
    if (dfs(nxt, cur) == 0) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int n, t;
  cin >> n >> t;

  adj.resize(n);
  pos.resize(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  cin >> st;
  st--;

  cout << (dfs(st, -1) ? "Ron" : "Hermione") << endl;
}