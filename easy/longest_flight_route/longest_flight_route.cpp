#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
  Longest path in a DAG
  - topo sort + DP
*/

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<vector<int>> rev(n);
  vector<int> indegree(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    rev[v].push_back(u);
    indegree[v]++;
  }

  deque<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) { q.push_back(i); } 
  }

  vector<int> top_sort;
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();
    top_sort.push_back(cur);

    for (int next : adj[cur]) {
      indegree[next]--;
      if (indegree[next] == 0) {
        q.push_back(next);
      }
    }
  }
  
  vector<int> parent(n, -1);
  vector<int> dp(n, -1);
  // can only find longest path from start city
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int cur = top_sort[i];
    for (int prev : rev[cur]) {
      if (dp[prev] == -1) { continue; }
      if (1 + dp[prev] > dp[cur]) {
        dp[cur] = 1+dp[prev];
        parent[cur] = prev;
      }
    }
  }

  if (dp[n-1] == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << dp[n-1] << "\n";
    vector<int> route = {n-1};
    while (parent[route.back()] != -1) {
      route.push_back(parent[route.back()]);
    }
    for (int i = route.size()-1; i >=0; i--) {
      cout << route[i]+1 << " ";
    }
  }
}