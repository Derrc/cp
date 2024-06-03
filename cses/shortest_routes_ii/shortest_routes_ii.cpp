#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Shortest path between any two nodes Floyd-Marshall
*/

const ll inf = 1e16;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  // dist[i][j] = shortest dist from node i to j
  vector<vector<ll>> dist(n, vector<ll>(n, inf));
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    // undirected graph
    dist[u][v] = min(dist[u][v], w);
    dist[v][u] = dist[u][v];
  }
  
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 0; i < q; i++) {
    ll a, b;
    cin >> a >> b;
    --a;
    --b;
    if (a == b) {
      dist[a][b] = 0;
    } else if (dist[a][b] == inf) {
      dist[a][b] = -1;
    }

    cout << dist[a][b] << "\n";
  }

}