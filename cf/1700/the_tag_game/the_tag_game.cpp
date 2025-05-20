#include <iostream>
#include <vector>
using namespace std;

// Find depth to leaves from both Alice and Bob's node.
// Optimal node for Bob is the furthest leaf node from Alice that can be reached before Alice.

vector<vector<int>> adj;

void dfs(int cur, int prev, int curDepth, vector<int> &dist) {
  bool isLeaf = 1;
  for (int next : adj[cur]) {
    if (next != prev) {
      isLeaf = 0;
      dfs(next, cur, curDepth + 1, dist);
    }
  }
  if (isLeaf) {
    dist[cur] = curDepth;
  }
}

int main() {
  int n, x;
  cin >> n >> x;

  adj.resize(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  vector<int> distA(n, -1);
  vector<int> distB(n, -1);
  distA[0] = 0;
  distB[--x] = 0;

  dfs(0, -1, 0, distA);
  dfs(x, -1, 0, distB);

  int furthestReachableNode = 0;
  for (int i = 1; i < n; i++) {
    if (distA[i] == -1) { continue; }
    if (distA[i] > distA[furthestReachableNode] && distB[i] < distA[i]) {
      furthestReachableNode = i;
    }
  }

  cout << 2 * distA[furthestReachableNode] << "\n";
}