#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+5;

// dp[i] = min cost to get to stone i
// rr:
// dp[i] = min(dp[i-1] + |h[i] - h[i-1]|, dp[i-2] + |h[i] - h[i-2]|)
// dp[1] = 0
int dp[N]{};
int h[N]{};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    dp[0] = 0, dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        const int ih = i-1;
        dp[i] = dp[i-1] + abs(h[ih] - h[ih-1]);
        if (i > 2) {
            dp[i] = min(
                dp[i],
                dp[i-2] + abs(h[ih] - h[ih-2]));
        }
    }

    cout << dp[n] << endl;
}