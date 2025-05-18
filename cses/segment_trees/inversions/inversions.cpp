#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// given a permutation p of n elements (1-n), count the number of inversions: the number of elements to the left which are greater

// start with empty tree
// leaf node p[i] being 1 will mean that p[i] has been visited
// for each element p[i] -> query range (p[i], n] -> gives us elements to the left of p[i] (already visited) that are greater
// set node p[i] = 1

class SST {
  private:
    vector<int> segtree;
    int n;

  public:
    SST(int n) : n(n), segtree(n*4, 0) {}

    void set(int i, int val, int cur, int l, int r) {
      if (l == r) {
        segtree[cur] = val;
        return;
      }

      int m = l + (r-l) / 2;
      if (i <= m) {
        set(i, val, cur*2, l, m);
      } else {
        set(i, val, cur*2+1, m+1, r);
      }

      segtree[cur] = segtree[cur*2] + segtree[cur*2+1];
    }

    int range_sum(int start, int end, int cur, int l, int r) {
      if (l > end || r < start) { return 0; }
      if (start <= l && r <= end) { return segtree[cur]; }

      int m = l + (r-l) / 2;
      int l_res = range_sum(start, end, cur*2, l, m);
      int r_res = range_sum(start, end, cur*2+1, m+1, r);
      return l_res + r_res;
    }
};

int main() {
  int n;
  cin >> n;

  vector<int> p(n);
  SST sst(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = sst.range_sum(p[i], n-1, 1, 0, n-1);
    sst.set(p[i], 1, 1, 0, n-1);
  }

  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
}