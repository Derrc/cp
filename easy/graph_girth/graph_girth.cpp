#include <iostream>
#include <vector>
#include <deque>
using namespace std;

const int inf = INT32_MAX;

int n, m;
vector<vector<int>> adj;

int cycle_len(int start) {
  int min_len = inf;

  deque<int> q = {start};
  vector<int> dist(n, -1);
  dist[start] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    for (int neighbor : adj[cur]) {
      // not visited yet
      if (dist[neighbor] == -1) {
        dist[neighbor] = dist[cur]+1;
        q.push_back(neighbor);
      }
      // visited but is not prev visited node
      // already visited node must have same or longer path since bfs
      else if (dist[neighbor] >= dist[cur]) {
        min_len = min(min_len, dist[neighbor]+dist[cur]+1);
      }
    }
  }

  return min_len;
}

int main() {
  cin >> n >> m;

  adj.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  int min_cycle = inf;
  // try min cycle that goes through every node 1-n
  for (int i = 0; i < n; i++) {
    min_cycle = min(min_cycle, cycle_len(i));
  }

  cout << (min_cycle == inf ? -1 : min_cycle) << endl;
}