#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
  DP, O(n) time
  - calculate longest dist to leaf for each child node
  - max diameter for current node will be top 2 child nodes with longest dist to leaf + 2
*/

vector<vector<int>> adj;
// holds distance to leaf from node i
vector<int> dp;

int leaf(int node, int prev) {
  if (dp[node] != 0) { return dp[node]; }

  int dist = 0;
  for (int child : adj[node]) {
    if (child == prev) { continue; }

    dist = max(dist, 1 + leaf(child, node));
  }

  dp[node] = dist;
  return dist;
}

int dfs(int node, int prev) {
  int max_diameter = 0;
  priority_queue<int> pq;

  for (int child : adj[node]) {
    if (child == prev) { continue; }
    pq.push(1 + leaf(child, node));
  }

  // only pop off top 2 children with greatest leaf distance
  int cur = 0;
  while (!pq.empty() && cur < 2) {
    max_diameter += pq.top();
    pq.pop();
    cur++;
  }

  // recurse on children
  for (int child : adj[node]) {
    if (child == prev) { continue; }
    max_diameter = max(max_diameter, dfs(child, node));
  }

  return max_diameter;
}

int main() {
  int n;
  cin >> n;

  adj.resize(n);
  dp.resize(n);

  for (int i = 0; i < n-1; i++) {
    int start, end;
    cin >> start >> end;
    adj[--start].push_back(--end);
    adj[end].push_back(start);
  }

  cout << dfs(0, -1);
}