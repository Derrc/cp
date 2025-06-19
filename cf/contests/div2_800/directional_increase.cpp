#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// All increases must also be decreased at some point to return to index 1
// Prefix sums of a must equal 0
// Conditions
// - prefix sum can never be < 0 since that means we had more decreases than increases from [0, i]
// - once prefix sum is 0 at index i, every index j > i must also be 0 (never reached)

constexpr int N = 2e5 + 5;
int a[N]{};
ll ps[N]{};

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        ps[i+1] = ps[i] + a[i];
    }

    if (ps[n] != 0) {
        cout << "NO" << "\n";
        return;
    }

    bool isZero = false;
    for (int i = 1; i <= n; i++) {
        if (ps[i] < 0 || (isZero && ps[i] != 0)) {
            cout << "NO" << "\n";
            return;
        }
        if (ps[i] == 0) {
            isZero = true;
        }
    }

    cout << "YES" << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
