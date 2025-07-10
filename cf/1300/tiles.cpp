#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 998244353;

// First tile has 4 orientations that it can be placed
// Tile that only shares 1 side has 2 orientations
// Tile that shares 2 sides only has 1 orientation
// Problem becomes -> 2^(w+h)

ll exp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int w, h;
    cin >> w >> h;

    cout << exp(2, w + h) << endl;
}