#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> coins(n);
  int max_sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
    max_sum += coins[i];
  }

  vector<vector<bool>> dp(max_sum+1, vector<bool>(n+1));
  dp[0][0] = true;
  int count = 0;

  for (int i = 0; i <= max_sum; i++) {
    for (int j = 1; j <= n; j++) {
      int value = coins[j-1];

      // current coin is not included as part of sum
      dp[i][j] = dp[i][j-1];
      if (i - value >= 0) {
        // current coin is included as part of sum
        dp[i][j] = dp[i][j] || dp[i-value][j-1];
      }
    }

    // check if current sum is possible
    if (i >= 1 && dp[i][n]) {
      count++;
    }
  }

  cout << count << "\n";

  for (int i = 1; i <= max_sum; i++) {
    if (dp[i][n]) {
      cout << i << " ";
    }
  }
}