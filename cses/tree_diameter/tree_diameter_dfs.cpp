#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int dist[maxN];

int dfs(int cur, int prev, int curDepth) {
  dist[cur] = curDepth;
  int maxDepthNode = cur;
  for (int nxt : adj[cur]) {
    if (nxt != prev) {
      int x = dfs(nxt, cur, curDepth + 1);
      if (dist[x] > dist[maxDepthNode]) {
        maxDepthNode = x;
      }
    }
  }
  return maxDepthNode;
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

  int startN = dfs(0, -1, 0);
  int endN = dfs(startN, -1, 0);

  cout << dist[endN] << endl;

  return 0;
}