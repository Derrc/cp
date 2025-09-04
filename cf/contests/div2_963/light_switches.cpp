#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// mod + sliding window (circular sliding window)

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<int> d(2*k);
    ll mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        d[a[i] % (2*k)]++;
    }

    // window of size k must sum up to n
    // for segment [r-k+1, r] to have all lights on at time r
    // i.e. light must have been activated within the last k minutes
    int cur = 0;
    for (int i = 0; i < k-1; i++) {
        cur += d[i];
    }

    ll ans = INT32_MAX;
    int l = 0, r = k-1;
    while (l < 2*k) {
        r %= 2*k;
        cur += d[r];

        if (cur == n) {
            ll offset = (r-mx) % (2*k);
            if (offset < 0) {
                offset += 2*k;
            }
            ans = min(ans, mx+offset);
        }

        cur -= d[l];
        l++;
        r++;
    }

    if (ans == INT32_MAX) {
        ans = -1;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}