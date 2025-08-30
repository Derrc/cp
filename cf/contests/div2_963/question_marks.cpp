#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int cnt[4]{};
    for (int i = 0; i < 4*n; i++) {
        char ch;
        cin >> ch;

        if (ch == '?') { continue; }
        cnt[ch - 'A']++;
    }

    int res = 0;
    for (int c : cnt) {
        res += min(c, n);
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
