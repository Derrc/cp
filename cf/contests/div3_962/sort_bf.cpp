#include <bits/stdc++.h>
using namespace std;

// TLE, brute force count diff b/w chars in range

int aCnt[26]{};
int bCnt[26]{};

void solve() {
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < q; i++) {
        memset(aCnt, 0, sizeof(aCnt));
        memset(bCnt, 0, sizeof(bCnt));

        int l, r;
        cin >> l >> r;
        l--;
        r--;

        for (int j = l; j <= r; j++) {
            aCnt[a[j] - 'a']++;
            bCnt[b[j] - 'a']++;
        }

        int diff = 0;
        for (int k = 0; k < 26; k++) {
            if (aCnt[k] != bCnt[k]) {
                diff += abs(aCnt[k] - bCnt[k]);
            }
        }

        cout << diff / 2 << "\n";
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}