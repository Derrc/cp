#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MAX_N = 1e6;
const ll MOD = 1e9 + 7;

// computes a^b using binary exponentiation
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
  int n;
  cin >> n;

  // precompute factorials up to MAX_N
  vector<ll> factorials(MAX_N + 1);
  factorials[0] = 1;
  for (int i = 1; i <= MAX_N; i++) {
    factorials[i] = i * factorials[i-1] % MOD;
  }

  // precompute modular inverses up to MAX_N
  vector<ll> inverses(MAX_N + 1);
  // get modular inverse with Fermat's Little Theorem i^(p-2) * i = 1 mod(p)
  inverses[MAX_N] = exp(factorials[MAX_N], MOD - 2);
  for (int i = MAX_N-1; i >= 0; i--) {
    inverses[i] = inverses[i+1] * (i+1) % MOD;
  }

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    // compute a choose b
    ll comb = factorials[a] * inverses[b] % MOD * inverses[a - b] % MOD; // MOD before mult to avoid overflow
    cout << comb << "\n";
  }
}