#include <bits/stdc++.h>
using namespace std;

// dp[i][j] = minimum skip points to beat first i bosses with last turn j
// j = 0 -> my turn
// j = 1 -> friend's turn
// Cases:
// Base: for i <= 2 -> dp[i][0] = sum(a[i] for i <= 2)
// 1. j = 1 -> dp[i][j] = dp[i-2][0]
// 2. j = 0 -> dp[i][j] = min(dp[i-2][1] + a[i-1] + a[i], dp[i-1][1] + a[i])

int constexpr N = 2e5 + 5;
int constexpr INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    vector<vector<int>> dp(n+1, vector<int>(2, INF));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1][0] = a[1];
    dp[2][0] = dp[1][0] + a[2];
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 1) {
                dp[i][j] = min(dp[i-2][0], dp[i-1][0]);
            } else {
                dp[i][j] = min(
                dp[i-2][1] + a[i-1] + a[i],
                dp[i-1][1] + a[i]
            );
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << "\n";
    //     cout << dp[i][0] << " " << dp[i][1] << "\n";
    // }

    cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    cout << endl;
}
