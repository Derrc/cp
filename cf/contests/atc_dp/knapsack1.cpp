#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// N = # of items
// C = max capacity of N items
constexpr int N = 105;
constexpr int C = 1e5+5;

// dp[i][j] = maximum value using first i items with a max capacity of j
// rr:

// If item i is part of the set, remaining work is to find the maximum value of
// the first i-1 items with a max capacity of j-w[i]
// If item i is not part of the set, dp[i][j] = dp[i-1][j], in other words
// finding the maximum value using the first i items is the same as using the first i-1 items

// dp[i][j] = max(v[i] + dp[i-1][j-w[i]], dp[i-1][j])
// dp[0][j] = 0
ll dp[N][C]{};
ll w[N]{};
ll v[N]{};

int main() {
    int n, c;
    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            dp[i][j] = dp[i-1][j];
            // item i can only be included if current capacity j allows
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j-w[i]]);
            }
        }
    }

    cout << dp[n][c] << endl;
}
