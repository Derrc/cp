#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += s[i] == s[n-1];
        }

        cout << n - cnt << "\n";
    }

    cout << endl;
}