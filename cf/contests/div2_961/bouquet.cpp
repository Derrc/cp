#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll N = 2e5 + 5;

void solve() {
    ll n, m;
    cin >> n >> m;

    map<ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    ll res = 0;
    for (auto [x, c] : cnt) {
        ll pos = min(c, m / x);
        res = max(res, x * pos);
        if (cnt.count(x+1) == 0) {
            continue;
        }
        // brute force all possible combinations for x and x+1
        for (int i = 1; i <= pos; i++) {
            ll mRem = m - x * i;
            int j = min(cnt[x+1], mRem / (x+1));
            res = max(res, x * i + (x+1) * j);
        }
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}