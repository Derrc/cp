#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  Disjoint-Set Union: O(nlogn + qlogq + n + q)
  - sort k values in queries and relevance in edges
  - create graphs with edges >= k and check size of component containing our start node
*/

class DSU {
  private:
    vector<int> parents;
    vector<int> sizes;

  public:
    DSU(int n) : parents(n), sizes(n, 1) {
      for (int i = 0; i < n; i++) { parents[i] = i; }
    }

    int find(int u) {
      if (parents[u] != u) { parents[u] = find(parents[u]); }
      return parents[u];
    }

    bool unite(int u, int v) {
      int ur = find(u);
      int vr = find(v);
      if (ur == vr) { return false; }
      if (sizes[ur] > sizes[vr]) { swap(ur, vr); }
      parents[ur] = vr;
      sizes[vr] += sizes[ur];
      return true;
    }

    bool connected(int u, int v) {
      return find(u) == find(v);
    }

    int size(int u) {
      return sizes[find(u)];
    }
};

struct Edge {
  int p, q, r;
};

struct Query {
  int indx, k, v;
};

int cmpe(Edge e1, Edge e2) {
  return e1.r > e2.r;
}

int cmpq(Query q1, Query q2) {
  return q1.k > q2.k;
}

int main() {
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  vector<Edge> edges(n-1);
  for (int i = 0; i < n-1; i++) {
    int p, q, r;
    cin >> p >> q >> r;
    edges[i] = {--p, --q, r};
  }

  // save index of initial query for output order later
  vector<Query> queries(q);
  for (int i = 0; i < q; i++) {
    int k, v;
    cin >> k >> v;
    queries[i] = {i, k, --v};
  }

  sort(edges.begin(), edges.end(), cmpe);
  sort(queries.begin(), queries.end(), cmpq);


  vector<int> res(q);
  DSU dsu(n);
  int cur = 0;
  for (int i = 0; i < q; i++) {
    auto [indx, k, v] = queries[i];
    // create graph with all edges greater than current k
    while (cur < n-1 && edges[cur].r >= k) {
      auto [p, q, r] = edges[cur];
      dsu.unite(p, q);
      cur++;
    }

    res[indx] = dsu.size(v)-1;
  }

  for (int ans : res) {
    cout << ans << "\n";
  }
}