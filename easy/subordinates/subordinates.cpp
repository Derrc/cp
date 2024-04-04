#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
// holds number of sub nodes from node i
vector<int> counts;

void dfs(int node, int prev) {
  for (int child : adj[node]) {
    if (child == prev) { continue; }

    dfs(child, node);
    counts[node] += 1 + counts[child];
  }
}

int main() {
  int n;
  cin >> n;

  adj.resize(n);
  counts.resize(n);

  for (int i = 1; i < n; i++) {
    int boss;
    cin >> boss;
    adj[--boss].push_back(i);
    adj[i].push_back(boss);
  }

  dfs(0, -1);

  for (int i = 0; i < n; i++) {
    cout << counts[i] << " ";
  }
}