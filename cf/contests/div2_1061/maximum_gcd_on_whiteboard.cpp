#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> freq(n+1);
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    vector<int> pre(n+1);
    for (int i = 1; i <= n; i++) {
        pre[i] = freq[i] + pre[i-1];
    }

    int res = 0;
    for (int g = 1; g <= n; g++) {
        // GCD can be g if:
        // 1. There are freq(>=4g) + freq(g) + freq(2g) + freq(3g) >= n-k
        // Any of these values can be 0
        int cur = n - pre[min(n, 4*g-1)];
        cur += freq[g];
        if (2*g <= n) {
            cur += freq[2*g];
        }
        if (3*g <= n) {
            cur += freq[3*g];
        }
        if (cur >= n-k) {
            res = g;
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