#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        string s;
        while (a > 0 && b > 0) {
            s += "01";
            a--;
            b--;
        }
        while (a > 0) {
            s += '0';
            a--;
        }
        while (b > 0) {
            s += '1';
            b--;
        }

        cout << s << "\n";
    }
}