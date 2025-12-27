#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i];
    }

    bool hasB = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            hasB = true;
            break;
        }
    }

    for (int i = 0; i < q; i++) {
        if (!hasB) {
            cout << a[i] << "\n";
        } else {
            int res = 0;
            while (a[i] > 0) {
                for (char ch : s) {
                    if (a[i] == 0) { break; }
                    if (ch == 'A') {
                        a[i]--;
                    } else {
                        a[i] /= 2;
                    }
                    res++;
                }
            }

            cout << res << "\n";
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    cout << endl;
}