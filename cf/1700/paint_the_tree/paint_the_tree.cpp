#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  - takes 2(n-1) moves to traverse entire tree and return to start
  - 2(n-1)-d moves to traverse entire tree ending at final node where d is longest dist of node from start
*/

int const N = 2e5;

int n, a, b, mx;
vector<int> adj[N];
int dist[N];
int parent[N];
vector<int> path;

void dfs(int i, int prev) {
  for (int nxt : adj[i]) {
    if (nxt == prev) { continue; }
    dist[nxt] = dist[i]+1;
    mx = max(mx, dist[nxt]);
    dfs(nxt, i);
  }
}

void mid(int i, int prev) {
  if (i == b) {
    int cur = b;
    while (cur != -1) {
      path.push_back(cur);
      cur = parent[cur];
    }
    reverse(path.begin(), path.end());
    return;
  }

  for (int nxt : adj[i]) {
    if (nxt == prev) { continue; }
    parent[nxt] = i;
    mid(nxt, i);
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> a >> b;
    a--;
    b--;
    mx = 0;
    for (int i = 0; i < n; i++) { adj[i].clear(); }
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      adj[--u].push_back(--v);
      adj[v].push_back(u);
    }

    // starting nodes are the same
    // -> only have to traverse tree - longest dist from start
    if (a == b) {
      dist[a] = 0;
      dfs(a, -1);
      cout << 2*(n-1)-mx << "\n";
      continue;
    }

    // otherwise have to reach first red node, lower midpoint
    parent[a] = -1;
    path.clear();
    mid(a, -1);

    // get mid node and get longest dist
    int mo = path.size();
    int mn = path[(mo-1)/2];
    dist[mn] = 0;
    dfs(mn, -1);
    // number of moves is higher midpoint in even case
    cout << 2*(n-1)-mx+(mo/2) << "\n";
  }
}