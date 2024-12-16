#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// find index of kth one (kth one is 0-indexed with first one being the 0th one)
// equivalent to finding left-most prefix with sum k+1

// Combining
// - same as sum segment tree, just sum left and right together

// Find
// - start at root and if compare left and right subtree to k
// - left.sum >= k+1 -> go to left subtree
// - left.sum < k+1 -> go to right subtree

class KthST {
  private:
    vector<ll> segtree;
    int n;

    void build(vector<int> &arr, int x, int l, int r) {
      if (l == r) {
        segtree[x] = arr[l];
        return;
      }

      int m = l + (r-l)/2;
      build(arr, x*2, l, m);
      build(arr, x*2+1, m+1, r);
      segtree[x] = segtree[x*2] + segtree[x*2+1];
    }

  public:
    KthST(vector<int> &arr) : n(arr.size()), segtree(4*arr.size()) {
      build(arr, 1, 0, arr.size()-1);
    }

    // set index i to opposite value
    void set(int i, int x, int l, int r) {
      if (l == r) {
        segtree[x] = 1 - segtree[x];
        return;
      }

      int m = l + (r-l)/2;
      if (i <= m) {
        set(i, x*2, l, m);
      } else {
        set(i, x*2+1, m+1, r);
      }

      segtree[x] = segtree[x*2] + segtree[x*2+1];
    }

    ll find(int k, int x, int l, int r) {
      // return index once we are at leaf
      if (l == r) {
        return l;
      }

      int m = l + (r-l)/2;
      // check left subtree
      if (segtree[x*2] >= k+1) {
        return find(k, x*2, l, m);
      }
      // check right subtree subtracting sum in left subtree
      else {
        return find(k-segtree[x*2], x*2+1, m+1, r);
      }
    }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  KthST kst(a);
  vector<ll> res;
  for (int i = 0; i < m; i++) {
    int op;
    cin >> op;

    if (op == 1) {
      int ind;
      cin >> ind;

      kst.set(ind, 1, 0, n-1);
    } else {
      int k;
      cin >> k;

      res.push_back(kst.find(k, 1, 0, n-1));
    }
  }

  for (int i : res) {
    cout << i << "\n";
  }
}