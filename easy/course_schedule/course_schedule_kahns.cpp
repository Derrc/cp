#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
  Topological Sort Kahn's Algorithm
  - BFS
*/

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<int> indegree(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[--a].push_back(--b);
    indegree[b]++;
  }

  deque<int> q;
  // start at all "root" nodes, indegree=0
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) { q.push_back(i); }
  }

  vector<int> top_sort;
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();
    top_sort.push_back(cur);

    for (int next : adj[cur]) {
      // remove cur edge
      indegree[next]--;
      // if outgoing node has no other incoming edges it can be added to top_sort
      // otherwise it still has other nodes to process before this one
      if (indegree[next] == 0) {
        q.push_back(next);
      }
    }
  }

  // if cycle exists cycle will never to processed
  if (top_sort.size() != n) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << top_sort[i]+1 << " ";
    }
  }
}