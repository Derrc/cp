#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  Topological Sort:
  - sorting of a DAG such that for every edge (u, v) node u comes before node v in the ordering
*/

vector<vector<int>> adj;
vector<int> visited;
vector<int> top_sort;

void dfs(int node) {
  for (int next : adj[node]) {
    if (visited[next]) { continue; }
    visited[next] = 1;
    dfs(next);
  }
  // finished processing outgoing neighbors
  top_sort.push_back(node);
}

int main() {
  int n, m;
  cin >> n >> m;

  adj.resize(n);
  visited.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[--a].push_back(--b);
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = 1;
      dfs(i);
    }
  }

  // reverse to get correct ordering
  reverse(top_sort.begin(), top_sort.end());

  // we can access the node at the ith position but we need to know the position of the ith node
  vector<int> ind(n);
  for (int i = 0; i < n; i++) { ind[top_sort[i]] = i; }

  bool valid = true;
  for (int i = 0; i < n; i++) {
    for (int j : adj[i]) {
      if (ind[i] > ind[j]) {
        valid = false;
        goto answer;
      }
    }
  }

answer:
  if (valid) {
    for (int i = 0; i < n; i++) {
      cout << top_sort[i]+1 << " ";
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}