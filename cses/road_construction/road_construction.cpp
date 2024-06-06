#include <iostream>
#include <vector>
using namespace std;

/*
  Disjoint-Set Union
  - TC: any m (find or union ops) on n objects = amortized(mlogn)
  - each individual op is O(alpha(n)) where alpha is the ackermann function (grows slowly so basically constant time)
*/

class DisjointSets {
  private:
    vector<int> size;
    vector<int> parent;
    int largest;
  
  public:
    DisjointSets(int n) : size(n, 1), parent(n) {
      for (int i = 0; i < n; i++) {
        parent[i] = i;
      }
      largest = 1;
    }

    int find(int u) {
      if (parent[u] != u) {
        parent[u] = find(parent[u]);
      }
      return parent[u];
    }

    bool unite(int u, int v) {
      int u_root = find(u);
      int v_root = find(v);
      if (u_root == v_root) { return false; }

      if (size[u_root] > size[v_root]) {
        swap(u_root, v_root);
      }
      parent[u_root] = v_root;
      size[v_root] += size[u_root];
      largest = max(largest, size[v_root]);

      return true;
    }

    int getLargest() {
      return largest;
    }
};

int main() {
  int n, m;
  cin >> n >> m;

  DisjointSets dsu(n);
  int num_components = n;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    bool merged = dsu.unite(--u, --v);
    cout << (merged ? --num_components : num_components) << " ";
    cout << dsu.getLargest() << "\n";
  }
}