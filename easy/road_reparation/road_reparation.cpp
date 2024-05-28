#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
  Minimum spanning tree, Kruskal's
  - O(ElogV + ElogE)
  - Prim's could be better in dense graphs with linear sweeps where (edges approaches n^2)
*/

struct Edge {
  int u, v, w;
};

class DSU {
  private:
    vector<int> parents;
    vector<int> sizes;
  public:
    DSU(int n) : parents(n), sizes(n, 1) {
      for (int i = 0; i < n; i++) { parents[i] = i; }
    }
    int find(int u) {
      if (u != parents[u]) { parents[u] = find(parents[u]); }
      return parents[u];
    }
    int unite(int u, int v) {
      int u_root = find(u);
      int v_root = find(v);
      if (u_root == v_root) { return false; }
      if (sizes[u_root] > sizes[v_root]) { swap(u_root, v_root); }
      parents[u_root] = v_root;
      sizes[v_root] += sizes[u_root];
      return true;
    }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {--u, --v, w};
  }

  sort(edges.begin(), edges.end(), [] (Edge &e1, Edge &e2) -> bool {
    return e1.w < e2.w;
  });

  DSU dsu(n);
  ll cost = 0;
  int n_comps = n;
  for (auto [u, v, w] : edges) {
    // u and v are in separate comps (won't create cycle)
    if (dsu.unite(u, v)) {
      cost += w;
      n_comps--;
    }
  }

  if (n_comps != 1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << cost << endl;
  }
}