#include <iostream>
#include <vector>
using namespace std;

// Find tree diameter and distance from each end of the diameter to every node

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int dist[2][maxN];

int dfs(int cur, int prev, int d, int i) {
  dist[i][cur] = d;
  int maxDepthN = cur;
  for (int nxt : adj[cur]) {
    if (nxt != prev) {
      int x = dfs(nxt, cur, d + 1, i);
      if (dist[i][x] > dist[i][maxDepthN]) {
        maxDepthN = x;
      }
    }
  }
  return maxDepthN;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;

    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  int startN = dfs(0, -1, 0, 0);

  int endN = dfs(startN, -1, 0, 0);
  dfs(endN, -1, 0, 1);

  for (int i = 0; i < n; i++) {
    cout << max(dist[0][i], dist[1][i]) << " ";
  }

  return 0;
}