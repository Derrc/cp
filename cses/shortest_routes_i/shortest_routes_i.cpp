#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

/*
  Shortest path
*/

const ll inf = 1e18;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<ll> dist;
vector<bool> visited;

// O(n^2 + m), better in dense graphs where m approaches n^2
void dijkstra(int start) {
  dist[start] = 0;
  for (int i = 0; i < n; i++) {
    // process node with min dist
    int cur = -1;
    for (int j = 0; j < n; j++) {
      if (!visited[j] && (cur == -1 || dist[j] < dist[cur])) {
        cur = j;
      }
    }
    // no more reachable nodes
    if (dist[cur] == inf) { break; }

    visited[cur] = true;
    for (auto e : adj[cur]) {
      auto [v, w] = e;
      if (dist[cur]+w < dist[v]) {
        dist[v] = dist[cur]+w;
      }
    }
  }
}

// O(n + mlogm), better in sparse graphs
void dijkstra_pq(int start) {
  dist[start] = 0;
  // (dist, node)
  priority_queue<pair<ll, int>> pq;
  pq.push({0, start});
  while (!pq.empty()) {
    auto [d_cur, cur]= pq.top();
    pq.pop();

    // don't process node we've already visited
    if (-d_cur != dist[cur]) { continue; }

    for (auto e : adj[cur]) {
      auto [v, w] = e;
      if (dist[cur]+w < dist[v]) {
        dist[v] = dist[cur]+w;
        pq.push({-dist[v], v});
      }
    }
  }
}

int main() {
  cin >> n >> m;

  adj.resize(n);
  dist.resize(n, inf);
  visited.resize(n);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[--u].push_back({--v, w});
  }

  dijkstra_pq(0);

  for (int i = 0; i < n; i++) {
    cout << dist[i] << " ";
  }

}