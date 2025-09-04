#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+5;

// dp[i][j] = max happiness on day i, where we chose option j
// rr:
// dp[i][j] = j[i] + max(dp[i-1][j2], dp[i-1][j3])
// dp[1][0] = a[0]
// dp[1][1] = b[0]
// dp[1][2] = c[0]
int dp[N][3];
int a[N];
int b[N];
int c[N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // 0 = a, 1 = b, 2 = c
    dp[1][0] = a[0];
    dp[1][1] = b[0];
    dp[1][2] = c[0];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = a[i-1] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i-1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i-1] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}