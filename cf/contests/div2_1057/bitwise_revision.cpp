#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;

    int first = x & y;
    int second = y & z;
    int third = x & z;
    if (first == second && second == third) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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