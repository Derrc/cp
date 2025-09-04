#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+5;

// dp[i] = min cost to get to stone i
// rr:
// dp[i] = min(dp[i-j] + |h[i] - h[i-j]|) for j in [1, k]
// dp[1] = 0
int dp[N]{};
int h[N]{};

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    fill_n(dp, N, INT32_MAX);

    dp[0] = 0, dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = k; j > 0; j--) {
            if (i - j > 0) {
                dp[i] = min(dp[i], dp[i-j] + abs(h[i-1] - h[i-j-1]));
            }
        }
    }

    cout << dp[n] << endl;
}