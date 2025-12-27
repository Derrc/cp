#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll constexpr INF = 1e18;

vector<ll> a;
vector<vector<ll>> dp;

ll dfs(int i, int j) {
    if (i == 0) {
        return 0;
    }
    if (dp[i][j] != INF) {
        return dp[i][j];
    }

    ll res = INF, mn = INF;
    for (int d = 1; d <= i && j-d+1 >= 0; d++) {
        mn = min(mn, a[i-d+1]);
        res = min(res, dfs(i-d, j-d+1) + d * mn);
    }

    return dp[i][j] = res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    a.resize(n+1);
    dp.assign(n+1, vector<ll>(k+1, INF));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << dfs(n, k) << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    cout << endl;
}