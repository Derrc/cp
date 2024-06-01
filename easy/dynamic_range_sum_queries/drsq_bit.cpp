#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Binary-Indexed Trees (BIT) or Fenwick Trees
  - O(logn) operations for point update and getting range sum
*/

class BIT {
  private:
    int n;
    vector<ll> bit;
    vector<int> arr;
  
  public:
    BIT(int n) : n(n), bit(n+1), arr(n) {}

    // sets value at i to val
    void set(int i, int val) {
      // need to add the difference
      int diff = val-arr[i];
      arr[i] += diff;
      // bit is 1-indexed
      i++;
      // update all ranges that i is in -> O(logn) ranges
      for (; i <= n; i += i&-i) {
        bit[i] += diff;
      }
    }

    // sum of [0, i]
    ll pref_sum(int i) {
      ll cur = 0;
      i++;
      // add all ranges -> O(logn) ranges
      for (; i > 0; i -= i&-i) {
        cur += bit[i];
      }

      return cur;
    }
};

int main() {
  int n, q;
  cin >> n >> q;

  BIT bit(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    bit.set(i, num);
  }

  for (int i = 0; i < q; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      bit.set(a-1, b);
    } else {
      cout << bit.pref_sum(b-1) - bit.pref_sum(a-2) << "\n";
    }
  }
}