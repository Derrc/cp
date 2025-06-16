#include <bits/stdc++.h>
using namespace std;

int constexpr N = 105;
int a[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            res += a[i] - m;
        }
        m = max(0, m - a[i]);
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