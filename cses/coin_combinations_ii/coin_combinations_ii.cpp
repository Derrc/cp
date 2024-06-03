#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  vector<ll> dp(x+1);
  dp[0] = 1;

  // iterate through set of coins once -> prevents duplicate combinations with different ordering
  for (int c : coins) {
    for (int i = 1; i <= x; i++) {
      if (i - c >= 0) {
        dp[i] = (dp[i] + dp[i - c]) % MOD;
      }
    }
  }

  cout << dp[x] << endl;
}