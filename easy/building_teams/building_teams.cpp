#include <iostream>
#include <vector>
using namespace std;

/*
  Bipartite Graph Problem (2-Color)
  - run a DFS coloring nodes either red or blue
  - if we run into a neighbor that is colored the same as the current node, we know that the graph is not bipartite
*/

vector<vector<int>> adj;
// 0 = no team, 1 = red team, 2 = blue team
vector<int> team;

void dfs(int node, int color) {
  team[node] = color;

  for (int neighbor : adj[node]) {
    if (team[neighbor] != 0 && team[neighbor] + team[node] != 3) {
      cout << "IMPOSSIBLE";
      exit(0);
    }
    if (team[neighbor] != 0) { continue; }

    dfs(neighbor, 3 - color);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  adj.resize(n);
  team.resize(n);

  vector<pair<int, int>> friends(m);
  for (int i = 0; i < m; i++) {
    cin >> friends[i].first >> friends[i].second;
    // 0-index
    friends[i].first--;
    friends[i].second--;
  }

  for (int i = 0; i < m; i++) {
    adj[friends[i].first].push_back(friends[i].second);
    adj[friends[i].second].push_back(friends[i].first);
  }

  for (int node = 0; node < n; node++) {
    if (team[node] == 0) {
      dfs(node, 1);
    }
  }

  for (int p = 0; p < n; p++) {
    cout << team[p] << " ";
  }
}