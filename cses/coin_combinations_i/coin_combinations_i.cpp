#include <iostream>
#include <vector>
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

  vector<ll> dp(x + 1);
  dp[0] = 1;

  for (int i = 1; i <= x; i++) {
    ll ways = 0;
    for (int c : coins) {
      if (i - c >= 0) {
        ways = (ways + dp[i - c]) % MOD;
      }
    }
    dp[i] = ways;
  }

  cout << dp[x] << endl;
}