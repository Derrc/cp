#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  DP
*/

const ll MOD = 1e9 + 7;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int rem = n;
    for (int i = 0; i < k; i++) {
      int r, c;
      cin >> r >> c;
      if (r == c) { rem--; }
      else {
        rem -= 2;
      }
    }

    if (rem == 0) {
      cout << 1 << "\n";
      continue;
    }

    // dp[i] = final configurations with i free rows + cols
    vector<ll> dp(rem+1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= rem; i++) {
      // place at (i, i) -> removes 1 r+c (1 option)
      // place at (i, j) and (j, i) -> removes 2 r+c (2i-2 options)
      dp[i] = dp[i-1] + (2 * i - 2) * dp[i-2];
      dp[i] %= MOD;
    }

    cout << dp[rem] << "\n";
  }
}