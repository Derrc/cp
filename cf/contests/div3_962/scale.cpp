#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];

void solve() {
    int n, k;
    cin >> n >> k;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> grid[r][c];
        }
    }

    int nk = n / k;
    for (int r = 0; r < nk; r++) {
        for (int c = 0; c < nk; c++) {
            cout << grid[r * k][c * k];
        }
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}