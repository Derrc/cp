#include <iostream>
#include <vector>
using namespace std;

/*
  Knapsack DP
*/

int main() {
  freopen("feast.in", "r", stdin);
  freopen("feast.out", "w", stdout);

  int t, a, b;
  cin >> t >> a >> b;

  // dp[i][j] represents whether fullness j is possible
  // i = 0: hasn't halfed with drink, i = 1: has halfed with drink
  vector<vector<bool>> dp(2, vector<bool>(t + 1));
  dp[0][0] = true;

  // get reachable states before halfing
  for (int i = 0; i <= t; i++) {
    if (i - a >= 0) {
      dp[0][i] = dp[0][i] || dp[0][i - a];
    }
    if (i - b >= 0) {
      dp[0][i] = dp[0][i] || dp[0][i - b];
    }
    // half at each step
    dp[1][i / 2] = dp[1][i / 2] || dp[0][i];
  }


  // iterate through again to see reachable states after halfing
  for (int i = 0; i <= t; i++) {
    if (i - a >= 0) {
      dp[1][i] = dp[1][i] || dp[1][i - a];
    }
    if (i - b >= 0) {
      dp[1][i] = dp[1][i] || dp[1][i - b];
    }
  }

  for (int i = t; i >= 0; i--) {
    if (dp[1][i]) {
      cout << i << endl;
      break;
    }
  }
}