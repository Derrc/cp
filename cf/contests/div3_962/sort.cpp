#include <bits/stdc++.h>
using namespace std;

// Prefix sums for count of each char (26 O(N) arrays)

constexpr int N = 2e5 + 5;
int ps[2][26][N]{};
int cnt[26];

void solve() {
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            ps[0][i][j] = ps[0][i][j-1] + (a[j-1] - 'a' == i);
            ps[1][i][j] = ps[1][i][j-1] + (b[j-1] - 'a' == i);
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        int diff = 0;
        for (int j = 0; j < 26; j++) {
            int aCnt = ps[0][j][r] - ps[0][j][l-1];
            int bCnt = ps[1][j][r] - ps[1][j][l-1];
            diff += abs(aCnt - bCnt);
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