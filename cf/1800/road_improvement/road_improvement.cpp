#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

// Edge assignment
// Assign edges with increasing days, skipping day assignment from previous node

vector<vector<pii>> adj;
vector<vector<int>> assignment;
int maxDays = 0;

void dfs(int cur, int prev, int prevDay) {
  int curDay = 0;
  for (auto [next, edgeN] : adj[cur]) {
    if (next != prev) {
      if (curDay == prevDay) {
        curDay++;
      }
      assignment[curDay].push_back(edgeN);
      dfs(next, cur, curDay++);
    }
  }
  // 1-indexed here
  maxDays = max(maxDays, curDay);
}

int main() {
  int n;
  cin >> n;

  adj.resize(n);
  assignment.resize(n-1);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back({--v, i});
    adj[v].push_back({u, i});
  }

  dfs(0, -1, -1);

  cout << maxDays << "\n";
  for (int i = 0; i < maxDays; i++) {
    cout << assignment[i].size() << " ";
    for (int j = 0; j < assignment[i].size(); j++) {
      cout << ++assignment[i][j] << " ";
    }
    cout << "\n";
  }
}