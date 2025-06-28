#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k == n*n) {
        cout << 2 * n - 1 << endl;
        return;
    }
    if (k == 0) {
        cout << 0 << endl;
        return;
    }

    int res = 1;
    k -= n;

    if (k <= 0) {
        cout << res << endl;
        return;
    }

    for (int i = n-1; i >= 1; i--) {
        for (int j = 0; j < 2; j++) {
            k -= i;
            res++;
            if (k <= 0) {
                cout << res << endl;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}