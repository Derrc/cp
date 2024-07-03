#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Push DP
*/

const ll INF = 1e18;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // dp[i][j] = min sum using first i nums and j operations
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        ll mn = INF;
        for (int d = 0; i + d + 1 <= n && j + d <= k; d++) {
          mn = min(mn, a[i + d]);
          // segment of length d+1 needs d operations to minimize sum
          dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d], dp[i][j] + (d + 1) * mn);
        }
      }
    }

    ll res = INF;
    for (int i = 0; i <= k; i++) {
      res = min(res, dp[n][i]);
    }

    cout << res << "\n";
  }
}