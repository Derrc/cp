#include <iostream>
#include <vector>
using namespace std;

/*
  Connected Components Problem: DFS over all nodes
  - new roads = number of connected components in graph - 1 (1 road between each connected component)
*/

int n;
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int node) {
  if (visited[node]) { return; }

  visited[node] = true;

  for (int neighbor : adj[node]) {
    if (visited[neighbor]) { continue; }
    dfs(neighbor);
  }
}

int main() {
  int m;
  cin >> n >> m;

  visited.resize(n);
  adj.resize(n);

  vector<pair<int, int>> roads(m);
  for (int i = 0; i < m; i++) {
    cin >> roads[i].first >> roads[i].second;
    // 0-index
    roads[i].first--;
    roads[i].second--;
  }

  // create adjacency list
  for (int i = 0; i < m; i++) {
    adj[roads[i].first].push_back(roads[i].second);
    adj[roads[i].second].push_back(roads[i].first);
  }

  vector<int> new_roads;
  for (int node = 0; node < n; node++) {
    if (!visited[node]) {
      new_roads.push_back(node);
      dfs(node);
    }
  }

  cout << new_roads.size() - 1 << "\n";

  for (int i = 1; i < new_roads.size(); i++) {
    // 1-index again
    cout << new_roads[i]+1 << " " << new_roads[i-1]+1 << "\n";
  }
}