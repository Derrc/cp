#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// Assign a 2-coloring for the tree
// Iterate through one color (undirected graph) and add: total of opp color - # of neighbors
// 2^32 ~= 4.3 * 10^9
// Since 10^5 is max number of nodes -> 5 * 10^4 nodes can contribute up to 5 * 10^4 edges -> 2.5 * 10^9

// Alternatively, we can add an edge between every two nodes in set 0 and set 1 in the 2-coloring
// Total edges = |set0| * |set1| - (n-1)

vector<vector<int>> adj;
vector<int> assignment;
int cnts[2]{};

void dfs(int cur, int prev, int color) {
  assignment[cur] = color;
  cnts[color]++;
  for (int next : adj[cur]) {
    if (next != prev) {
      dfs(next, cur, 1 - color);
    }
  }
}

int main() {
  int n;
  cin >> n;
  
  adj.resize(n);
  assignment.resize(n, -1);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  dfs(0, -1, 0);

  cout << (ll)cnts[0] * cnts[1] - (n-1) << endl;
}