#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 1e9+7;
constexpr int R = 1005;
constexpr int C = 1005;

char grid[R][C];
// dp[i][j] = number of paths to grid[i][j]
// rr:
// dp[i][j] = dp[i-1][j] + dp[i][j-1]
// dp[0][0] = 1
ll dp[R][C]{};

int main() {
    int rows, cols;
    cin >> rows >> cols;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> grid[r][c];
        }
    }

    dp[0][0] = grid[0][0] != '#' ? 1 : 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '#') {
                continue;
            }
            if (r > 0) {
                dp[r][c] = dp[r-1][c] % mod;
            }
            if (c > 0) {
                dp[r][c] = (dp[r][c] + dp[r][c-1]) % mod;
            }
        }
    }

    cout << dp[rows-1][cols-1] << endl;
}