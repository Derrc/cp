#include <iostream>
#include <vector>
using namespace std;

/*
  Disjoint-Set Union
  - constant time for uniting
*/

class DisjointSets {
  private:
    vector<int> parent;
    vector<int> size;

  public:
    DisjointSets(int n) : parent(n), size(n, 1) {
      for (int i = 0; i < n; i++) {
        parent[i] = i;
      }
    }

    // returns representive (i.e. root) of tree containing node x
    int find(int u) {
      if (parent[u] != u) {
        // path compression
        parent[u] = find(parent[u]);
      }
      return parent[u];
    }

    // unites trees to have the same root
    void unite(int u, int v) {
      int u_root = find(u);
      int v_root = find(v);
      if (u_root == v_root) { return; }
      
      // set tree with more nodes as new root (less time to reach root for more nodes)
      if (size[u_root] < size[v_root]) {
        parent[u_root] = v_root;
        size[v_root] += size[u_root];
      } else {
        parent[v_root] = u_root;
        size[u_root] += size[v_root];
      }
    }

    bool connected(int u, int v) {
      return find(u) == find(v);
    }
};

int main() {
  int n, q;
  cin >> n >> q;

  DisjointSets dsu(n);
  for (int i = 0; i < q; i++) {
    int t, u, v;
    cin >> t >> u >> v;

    if (t == 0) {
      dsu.unite(u, v);
    } else {
      cout << dsu.connected(u, v) << "\n";
    }
  }

}