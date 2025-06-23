#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5 + 5;

int n;
int a[N]{};
bool seen[N]{};

void exec() {
    for (int i = 0; i < n; i++) {
        seen[a[i]] = false;
    }

    int maxN = 0;
    for (int i = 0; i < n; i++) {
        if (seen[a[i]]) {
            maxN = max(maxN, a[i]);
        }

        seen[a[i]] = true;
        a[i] = maxN;
    }
}

void solve() {
    cin >> n;

    ll res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res += a[i];
    }

    exec();
    for (int i = 0; i < n; i++) {
        res += a[i];
    }

    exec();
    for (int i = 0; i < n; i++) {
        res += (n - i) * (ll)a[i];
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}