#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = max(a[i], pre[i-1]);
    }

    ll res = 0;
    for (int i = 0; i < n; i+=2) {
        int diff = 0;
        if (i > 0) {
            diff = max(diff, a[i] - pre[i-1] + 1);
        }
        if (i < n-1) {
            diff = max(diff, a[i] - pre[i+1] + 1);
        }

        res += diff;
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