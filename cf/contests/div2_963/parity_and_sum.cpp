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

    ll maxOdd = -1;
    ll oddCnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            maxOdd = max(maxOdd, a[i]);
            oddCnt++;
        }
    }

    if (oddCnt == 0 || oddCnt == n) {
        cout << 0 << endl;
        return;
    }

    sort(a.begin(), a.end());

    ll res = n - oddCnt;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (a[i] < maxOdd) {
                maxOdd += a[i];
            } else {
                res++;
                break;
            }
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