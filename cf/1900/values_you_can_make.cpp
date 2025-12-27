#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// knapsack DP
// dp[i][j][k] = there exists a subset of sum j using the first i items, where a subset of items exists with sum k
// Cases:
// 1. i is not included -> dp[i][j][k] = dp[i-1][j][k]
// 2. i is included
// - i is in j but not in k -> dp[i][j][k] = dp[i-1][j-ai][k]
// - i is in both j and k -> dp[i][j][k] = dp[i-1][j-ai][k-ai]
// Answer is # of dp[n][k][x] that are true where x = [1, k]

int constexpr N = 505;

int a[N];
bool dp[N][N][N];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0][0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= k; x++) {
            for (int y = 0; y <= k; y++) {
                dp[i][x][y] = dp[i-1][x][y];
                if (x >= a[i]) {
                    dp[i][x][y] |= dp[i-1][x-a[i]][y];

                    if (y >= a[i]) {
                        dp[i][x][y] |= dp[i-1][x-a[i]][y-a[i]];
                    }
                }
            }
        }
    }

    vector<int> res;
    for (int i = 0; i <= k; i++) {
        if (dp[n][k][i]) {
            res.push_back(i);
        }
    }

    cout << res.size() << "\n";
    for (auto x : res) {
        cout << x << " ";
    }

    cout << endl;
}