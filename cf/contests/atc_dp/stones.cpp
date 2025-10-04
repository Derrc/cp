#include <bits/stdc++.h>
using namespace std;

constexpr int K = 1e5+5;
constexpr int N = 105;

int n, k;
// dp[i] = whether a state with i stones remaining is a winning state for the current player
// rr:
// if any sub-states are losing states, the current state is a winning state
// - current player can force a losing state for the other player
// if all sub-states are winning states, the current state is a losing state
// - current player cannot force a losing state for the other player
// dp[i] = dp[i-a1] NAND dp[i-a2] NAND ... for all ai in A
// dp[i] = false for all i < min(A)
bool dp[K]{};
int a[N];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = false;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0 && !dp[i - a[j]]) {
                dp[i] = true;
            }
        }
    }

    cout << (dp[k] ? "First" : "Second") << endl;
}