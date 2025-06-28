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

    for (int i = 1; i < n; i++) {
        if (a[i-1] != 1 && a[i] == 1) {
            cout << -1 << endl;
            return;
        }
    }

    vector<ll> ps(n, 0);
    for (int i = 1; i < n; i++) {
        ll prev = a[i-1], cur = a[i];
        ll cnt = 0;
        // if cur > prev -> reduce cur until 1 square greater than prev -> than same number of ops from prev -> prev prev
        while (prev != 1 && prev * prev <= cur) {
            prev *= prev;
            cnt--;
        }
        // if cur < prev -> square cur until greater than square ops from cur -> prev is additive to ops from prev -> prev prev
        while (prev > cur) {
            cur *= cur;
            cnt++;
        }

        // if sequence is already non-decreasing, we will have a negative prefix sum which we don't want to count
        ps[i] = max(0ll, ps[i-1] + cnt);
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += ps[i];
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