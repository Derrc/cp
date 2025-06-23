#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;

    vector<int> a(n);

    int cur = -1;
    for (int i = y-1; i >= 0; i--) {
        a[i] = cur;
        cur *= -1;
    }
    for (int i = y; i <= x; i++) {
        a[i] = 1;
    }
    cur = -1;
    for (int i = x+1; i < n; i++) {
        a[i] = cur;
        cur *= -1;
    }

    for (int i : a) {
        cout << i << " ";
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}