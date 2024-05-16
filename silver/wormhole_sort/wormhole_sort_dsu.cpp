#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  Disjoint-Set Union solution: O(n + m + mlogm)
  - sort wormholes in descending order
  - keep pointer on current wormhole
  - for each cow c, add wormholes until its in the same component as position[c]
*/

class DSU {
  private:
    vector<int> parent;
    vector<int> size;

  public:
    DSU(int n) : parent(n), size(n, 1) {
      for (int i = 0; i < n; i++) { parent[i] = i; }
    }

    int find(int u) {
      if (parent[u] != u) { parent[u] = find(parent[u]); }
      return parent[u];
    }

    bool unite(int u, int v) {
      int ur = find(u);
      int vr = find(v);
      if (ur == vr) { return false; }
      if (size[ur] > size[vr]) { swap(ur, vr); }
      parent[ur] = vr;
      size[vr] += size[ur];
      return true;
    }
};

struct Wormhole {
  int u, v, w;
};

int cmp(Wormhole w1, Wormhole w2) {
  return w1.w > w2.w;
};

int main() {
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<int> position(n);
  for (int i = 0; i < n; i++) {
    cin >> position[i];
    position[i]--;
  }

  vector<Wormhole> wormhole(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    wormhole[i] = {--u, --v, w};
  }

  sort(wormhole.begin(), wormhole.end(), cmp);

  DSU dsu(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    while (dsu.find(i) != dsu.find(position[i])) {
      int u = wormhole[cur].u, v = wormhole[cur].v;
      dsu.unite(u, v);
      cur++;
    }
  }

  cout << (cur == 0 ? -1 : wormhole[cur-1].w) << endl;
}