#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int res = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '0') { continue; }
        bool found = false;
        for (int j = i-k+1; j < i; j++) {
            if (j < 0) { continue; }
            if (s[j] == '1') {
                found = true;
                break;
            }
        }

        res += !found;
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