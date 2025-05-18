#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// first_above(x, l): find first index j where arr[j] >= x and j >= l

// Combining:
// - max segment tree

// first_above
// - start at root and compare left and right maxes to x
// - if left.max >= x and left segment contains l -> go to left
// - if we found it in left -> return
// - otherwise if right.max >= x -> go to right instead

class FAST {
  private:
    vector<ll> segtree;
    int n;

    void build(vector<ll> &arr, int cur, int l, int r) {
      if (l == r) {
        segtree[cur] = arr[l];
        return;
      }

      int m = l + (r-l)/2;
      build(arr, cur*2, l, m);
      build(arr, cur*2+1, m+1, r);
      segtree[cur] = max(segtree[cur*2], segtree[cur*2+1]);
    }

  public:
    FAST(vector<ll> &arr) : n(arr.size()), segtree(arr.size()*4) {
      build(arr, 1, 0, arr.size()-1);
    }

    void set(int i, int val, int cur, int l, int r) {
      if (l == r) {
        segtree[cur] = val;
        return;
      }

      int m = l + (r-l)/2;
      if (i <= m) {
        set(i, val, cur*2, l, m);
      } else {
        set(i, val, cur*2+1, m+1, r);
      }
      
      segtree[cur] = max(segtree[cur*2], segtree[cur*2+1]);
    }

    int first_above(int x, int i, int cur, int l, int r) {
      if (segtree[cur] < x) { return -1; }
      if (l == r) {
        return l;
      }

      int m = l + (r-l)/2;
      // i is in left segment and left.max >= x
      if (i <= m && segtree[cur*2] >= x) {
        int left = first_above(x, i, cur*2, l, m);
        // could be the case that max in left segment is before index i
        // in which then we would check right segment
        if (left != -1) {
          return left;
        }
      }
      // if either i was not in left segment or left.max < x
      // then we can search in right segment
      return first_above(x, i, cur*2+1, m+1, r);
    }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  FAST st(a);
  vector<int> res;
  for (int i = 0; i < m; i++) {
    int op;
    cin >> op;

    if (op == 1) {
      int ind, val;
      cin >> ind >> val;

      st.set(ind, val, 1, 0, n-1);
    } else {
      int x, ind;
      cin >> x >> ind;

      res.push_back(st.first_above(x, ind, 1, 0, n-1));
    }
  }

  for (int i : res) {
    cout << i << "\n";
  }
}