#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    long long res = n;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            res += i;
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
