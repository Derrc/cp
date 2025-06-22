#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int res = 0;
    int sum = 0;
    for (int i = n-1; i >= 0; i--) {
        int sn = s[i] - '0';
        int cur = (10 + sn - sum) % 10;

        sum = (sum + cur) % 10;
        res += cur + 1;
    }

    cout << res << endl;
}