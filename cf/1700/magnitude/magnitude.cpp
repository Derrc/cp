#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Greedy / Combinatorics
  - it is optimal to only have one "important" option 2 (flips neg to pos)
  - before this index i, option 2 can be chosen on any non-neg index, cannot be chosen elsewhere as it will lower the value of c
  - after this index i, option 2 can be chosen on any index, sum will always be positive after this point
  - other than index i, option 1 can be chosen on every index
*/

const ll mod = 998244353;
const ll max_n = 300005;

int main() {
  int t;
  cin >> t;

  vector<ll> p2(max_n);
  p2[0] = 1;
  for (int i = 1; i < max_n; i++) {
    p2[i] = 2 * p2[i-1] % mod;
  }

  while (t--) {
    int n;
    cin >> n;

    vector<ll> a(n);
    ll mn = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      mn = min(mn, sum);
    }
    // no "important" index if all prefix-sums are non-neg
    if (mn == 0) {
      cout << p2[n] << "\n";
      continue;
    }

    ll res = 0;
    // keep track of seen non-neg prefixes up to mn
    ll noneg = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum == mn) {
        res = (res + p2[n - 1 - i + noneg]) % mod;
      }
      if (sum >= 0) {
        noneg++;
      }
    }

    cout << res << "\n";
  }
}