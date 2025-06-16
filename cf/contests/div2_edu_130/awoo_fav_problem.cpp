#include <bits/stdc++.h>
using namespace std;

// a can only move to the right
// c can only move to the left
// a and c can never swap positions
// every ith occurrence of a should match in s and t -> a_i in s < a_j in t
// every ith occurrence of c should match in s and t -> c_i in s > c_j in t

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    if (count(s.begin(), s.end(), 'b') != count(t.begin(), t.end(), 'b')) {
        cout << "NO" << "\n";
        return;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') { continue; }
        while (t[j] == 'b') {
            j++;
        }

        if (s[i] != t[j] || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j)) {
            cout << "NO" << "\n";
            return;
        }
        j++;
    }

    cout << "YES" << "\n";
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        solve();
    }
}