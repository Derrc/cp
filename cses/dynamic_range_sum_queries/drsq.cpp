#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class SumSegmentTree {
  private:
    int n;
    vector<ll> segtree;
  public:
    SumSegmentTree(int n) : n(n), segtree(2*n) {}
    void set(int i, int val) {
      i += n;
      segtree[i] = val;
      for (; i > 1; i /= 2) {
        segtree[i/2] = segtree[i] + segtree[i^1];
      }
    }
    ll range_sum(int a, int b) {
      ll cur = 0;
      for (a += n, b += n; a <= b; a /= 2, b /= 2) {
        if (a % 2 == 1) { cur += segtree[a++]; }
        if (b % 2 == 0) { cur += segtree[b--]; }
      }
      return cur;
    }
};

int main() {
  int n, q;
  cin >> n >> q;

  SumSegmentTree sst(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    sst.set(i, num);
  }

  for (int i = 0; i < q; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      sst.set(a-1, b);
    } else {
      cout << sst.range_sum(a-1, b-1) << "\n";
    }
  }
}