#include <iostream>
using namespace std;
using ll = long long;

const ll M = 1e9 + 7;

/*
  Binary exponentiation
  - performs O(log n) multiplications vs. O(n) in naive approach
*/

// calculates a^b mod M using binary exponentiation
ll exp(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    // if lsb is set, we multiply by a^(bit)
    if (b & 1) {
      res = res * a % M;
    }
    a = a * a % M;
    // shift b right to check next bit
    b >>= 1;
  }

  return res;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;

    cout << exp(a, b) << "\n";
  }
}