#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        double a, b, n;
        cin >> a >> b >> n;

        if ((a / n) >= b || a == b) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }

    cout << endl;
}