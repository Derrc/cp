#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll res = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            ll cur = max(a[i], a[(i+1) % n]);
            res += cur;
            mx = max(cur, mx);
        }

        cout << res - mx << "\n";
    }

    cout << endl;
    return 0;
}