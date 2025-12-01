#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 0;
    ll mx = a[0];
    ll pmx = 0;
    for (int i = 1; i < n; i++) {
        mx = max(mx, a[i]);
        pmx = max(pmx, a[i-1]);
        if (i % 2 == 1) {
            if (a[i] > a[i-1]) { continue; }
            // a[i-1] > a[i]
            a[i] = mx;
            if (a[i] == a[i-1]) {
                a[i-1]--;
                res++;
            }
        } else {
            if (a[i] < a[i-1]) { continue; }
            // a[i-1] < a[i]
            if (pmx > a[i]) {
                a[i-1] = pmx;
                continue;
            }

            ll ops = min(
                abs(a[i] - a[i-1]) + 1,
                abs(a[i] - pmx) + 1
            );

            pmx = max(pmx, a[i]);
            a[i] -= ops;
            res += ops;
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