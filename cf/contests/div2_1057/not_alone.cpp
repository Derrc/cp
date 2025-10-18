#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll constexpr inf = 1e16;

ll cost(ll x, ll y) {
    return abs(x - y);
}

ll cost(ll x, ll y, ll z) {
    ll c1 = abs(x - y) + abs(y - z);
    ll c2 = abs(y - x) + abs(x - z);
    ll c3 = abs(x - z) + abs(z - y);
    return min(c1, min(c2, c3));
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> dp(n+1);
    ll res = inf;
    for (int s = 0; s < 3; s++) {
        dp[0] = 0;
        // for a3, cannot create a block of 2
        dp[1] = inf;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-2] + cost(a[i-2],a[i-1]);
            if (i > 2) {
                dp[i] = min(
                    dp[i],
                    dp[i-3] + cost(a[i-3], a[i-2], a[i-1])
                );
            }
        }
        res = min(res, dp[n]);

        // cyclic shift left
        for (int i = 1; i < n; i++) {
            swap(a[i], a[i-1]);
        }
    }

    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    cout << endl;
}