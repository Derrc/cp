#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int res = 0;
    while (n > 2) {
        res += n / 3;
        n = (n / 3) + (n % 3);
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