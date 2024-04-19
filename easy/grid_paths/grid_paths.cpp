#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Paths on Grid DP
*/

const ll MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cin >> grid[r][c];
    }
  }

  // case where upper-left is trapped
  if (grid[0][0] == '*') {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<ll>> dp(n, vector<ll>(n));
  dp[0][0] = 1;
  
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      // check if current cell is trapped
      if (grid[r][c] == '*') { continue; }

      if (r > 0) {
        dp[r][c] += dp[r-1][c];
      }
      if (c > 0) {
        dp[r][c] += dp[r][c-1];
      }

      dp[r][c] %= MOD;
    }
  }

  cout << dp[n-1][n-1] << endl;
}