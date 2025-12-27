#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// dp[i][j] = minimum sum using first i numbers and j operations
// Idea: we can construct dp[i][j] by creating segments of length d -> [1, d] and [d+1, i]
// Each segment of length d can be minimized using d-1 operations
// Keep track of running minimum from [i, 1] as we check segments

// for d in range(1, i+1):
//   mn = min(a[i-d+1], mn)
//   dp[i][j] = min(dp[i][j], dp[i-d][j-d+1]

ll constexpr INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n+1);
    vector dp(n+1, vector(k+1, INF));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            ll mn = INF;
            for (int d = 1; d <= i && j-d+1 >= 0; d++) {
                mn = min(mn, a[i-d+1]);
                dp[i][j] = min(dp[i][j], dp[i-d][j-d+1] + d * mn);
            }
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    cout << endl;
}