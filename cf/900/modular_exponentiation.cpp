#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }

    return res;
}

int main() {
    ll n, m;
    cin >> n >> m;

    if (n > 27) {
        cout << m << endl;
        return 0;
    }

    cout << m % exp(2, n) << endl;
}
