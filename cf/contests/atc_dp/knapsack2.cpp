#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;
constexpr int N = 105;
constexpr int MAX_V = 1e5+5;

// dp[i][j] = minimum weight using first i items with a max value of j
// rr:
// dp[i][j] = min(w[i] + dp[i-1][j-v[i]], dp[i-1][j])
// dp[0][0] = 0
ll dp[N][MAX_V]{};
ll w[N]{};
ll v[N]{};

int main() {
    int n, c;
    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAX_V; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAX_V; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= v[i]) {
                dp[i][j] = min(dp[i][j], w[i] + dp[i-1][j-v[i]]);
            }
        }
    }

    for (int i = MAX_V; i >= 0; i--) {
        if (dp[n][i] <= c) {
            cout << i << endl;
            return 0;
        }
    }
}