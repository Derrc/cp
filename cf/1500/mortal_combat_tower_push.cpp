#include <bits/stdc++.h>
using namespace std;

int constexpr INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    vector dp(n+1, vector(2, INF));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 0 = my turn
    // 1 = friend's turn
    dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int b = 1; b <= min(n-i, 2); b++) {
                int skips = a[i] + (b > 1 ? a[i+1] : 0);
                dp[i + b][1-j] = min(
                    dp[i + b][1-j],
                    dp[i][j] + j * skips
                );
            }
        }
    }

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