#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// max sum in a segment
// store (maxSum, sum, pref, suf) in node
// maxSum: max sum of segment
// sum: sum of segment
// pref: max prefix sum of segment
// suf: max suffix sum of segment

// Combining
// - when combining two segments, the max sum of the combined segment can either be the left, right, or a middle segment that overlaps left and right
// - keep track of max prefix and suffix of each segment: then answer becomes max(left, right, left.suffix + right.prefix)
// - suffix of combined segment will be either the max suffix in right or the entire right segment + max suffix in left
// - similarly, the prefix of the combined segment will either be the max prefix in left or the entire left segment + max prefix in right
// - therefore we need to keep track of the sum of each segment as well in each node

struct Node {
  ll maxSum, sum, pref, suf;
};

class MSST {
  private:
    vector<Node> segtree;
    int n;

    void build(vector<int> &arr, int x, int l, int r) {
      if (l == r) {
        segtree[x] = Node{arr[l], arr[l], arr[l], arr[l]};
        return;
      }

      int m = l + (r-l) / 2;
      build(arr, x << 1, l, m);
      build(arr, (x << 1) | 1, m+1, r);
      segtree[x] = combine(segtree[x << 1], segtree[(x << 1) | 1]);
    }

    Node combine(Node &l, Node &r) {
      Node cur;
      cur.sum = l.sum + r.sum;
      cur.pref = max(l.pref, l.sum + r.pref);
      cur.suf = max(r.suf, l.suf + r.sum);
      cur.maxSum = max(l.maxSum, max(r.maxSum, l.suf + r.pref));
      return cur;
    }

  public:
    MSST(vector<int> arr) : n(arr.size()), segtree(4*arr.size()) {
      build(arr, 1, 0, arr.size()-1);
    }

    // x = position of root node
    void set(int i, int val, int x, int l, int r) {
      if (l == r) {
        segtree[x] = Node{val, val, val, val};
        return;
      }

      int m = l + (r - l) / 2;
      if (i <= m) {
        // in left subtree
        set(i, val, x << 1, l, m);
      } else {
        // in right subtree
        set(i, val, (x << 1) | 1, m+1, r);
      }

      segtree[x] = combine(segtree[x << 1], segtree[(x << 1) | 1]);
    }

    ll max_segment() {
      return max(segtree[1].maxSum, (ll)0);
    }

    Node max_segment_range(int l, int r, int cur, int cur_l, int cur_r) {
      if (cur_r < l || cur_l > r) { return Node{0, 0, 0, 0}; }
      if (l <= cur_l && cur_r <= r) { return segtree[cur]; }

      int m = cur_l + (cur_r - cur_l) / 2;
      Node l_res = max_segment_range(l, r, cur << 1, cur_l, m);
      Node r_res = max_segment_range(l, r, (cur << 1) | 1, m+1, cur_r);
      return combine(l_res, r_res);
    }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  MSST msst(a);
  vector<ll> res = {max(msst.max_segment_range(0, n-1, 1, 0, n-1).maxSum, (ll)0)};
  for (int i = 0; i < m; i++) {
    int ind, val;
    cin >> ind >> val;
    msst.set(ind, val, 1, 0, n-1);
    res.push_back(max(msst.max_segment_range(0, n-1, 1, 0, n-1).maxSum, (ll)0));
  }

  for (int i : res) {
    cout << i << "\n";
  }
}