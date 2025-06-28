#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

const ld eps = 1e-9;

void solve() {
    int n;
    cin >> n;

    vector<ld> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        if (a[i-1] != 1 && a[i] == 1) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = log(log(a[i]));
    }

    ll res = 0;
    for (int i = 1; i < n; i++) {
        ld diff = a[i-1] - a[i];
        if (diff > eps) {
            int ops = ceil((diff - eps) / log(2));
            a[i] += ops * log(2);
            res += ops;
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