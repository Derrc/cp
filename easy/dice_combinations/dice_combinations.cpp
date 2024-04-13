#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<ll> dp(n + 1);
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    ll ways = 0;
    for (int j = 1; j <= 6; j++) {
      if (i-j >= 0) {
        ways = (ways + dp[i-j]) % MOD;
      }
    }
    dp[i] = ways;
  }

  cout << dp[n] << endl;

}