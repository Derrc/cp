#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    map<ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        cnt[a[i]] = c[i];
    }

    ll res = 0;
    for (auto [x, c] : cnt) {
        ll k1 = min(c, m / x);
        res = max(res, x * k1);
        if (cnt.count(x+1) == 0) {
            continue;
        }

        ll remM = m - x * k1;
        ll k2 = min(cnt[x+1], remM / (x+1));
        remM -= (x+1) * k2;
        // # of x -> x+1 replacements (increases value by 1)
        ll r = min(min(remM, k1), cnt[x+1] - k2);
        res = max(res, (k1 - r) * x + (k2 + r) * (x+1));
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