#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        while (i < n-1 && a[i] == a[i+1]) {
            cnt++;
            i++;
        }

        if (cnt % 2 != 0) {
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}