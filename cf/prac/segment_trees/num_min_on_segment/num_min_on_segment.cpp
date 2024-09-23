#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// dynamic range queries: minimum and number of elements equal to minimum
// store node (m, c) where m is minimum of current segment and c is count of min

const ll inf = 1e13;

struct Node {
  ll m, c;
};

class MST {
  private:
    vector<Node> segtree;
    int n;

    void build(vector<int> &arr) {
      for (int i = 0; i < n; i++) {
        segtree[i + n] = Node{arr[i], 1};
      }
      for (int i = n-1; i > 0; i--) {
        segtree[i] = combine(segtree[i << 1], segtree[(i << 1) + 1]);
      }
    }

    Node combine(Node &a, Node &b) {
      Node cur;
      if (a.m == b.m) {
        cur.m = a.m;
        cur.c = a.c + b.c;
      } else if (a.m < b.m) {
        cur = a;
      } else {
        cur = b;
      }
      return cur;
    }

  public:
    MST(vector<int> &arr) : n(arr.size()), segtree(2*arr.size(), Node{inf, 0}) {
      build(arr);
    }

  void set(int i, int val) {
    i += n;
    segtree[i] = {val, 1};
    for (; i > 1; i /= 2) {
      segtree[i / 2] = combine(segtree[i], segtree[i ^ 1]);
    }
  }

  Node range_min_cnt(int a, int b) {
    Node res = {inf, 0};
    for (a += n, b += n; a <= b; a /= 2, b /= 2) {
      if (a % 2 == 1) {
        res = combine(res, segtree[a++]);
      }
      if (b % 2 == 0) {
        res = combine(res, segtree[b--]);
      }
    }
    return res;
  }
};


int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  MST mst(a);
  vector<Node> res;
  for (int i = 0; i < m; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, v;
      cin >> i >> v;
      mst.set(i, v);
    } else {
      int l, r;
      cin >> l >> r;
      res.push_back(mst.range_min_cnt(l, r));
    }
  }

  for (auto [min, cnt] : res) {
    cout << min << " " << cnt << "\n";
  }
}