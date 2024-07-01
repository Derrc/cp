#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Binary exponentiation / prefix sums
*/

const ll MOD = 1e9 + 7;

ll exp(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    ll l, r, k;
    cin >> l >> r >> k;

    int lim = 9 / k;
    // keep positive
    cout << (exp(lim + 1, r) - exp(lim + 1, l) + MOD) % MOD << "\n";
  }
}