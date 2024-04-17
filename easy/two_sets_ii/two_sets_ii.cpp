#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Knapsack DP: use dp to keep track of ways to sum to [1, n] using numbers from [1, n] once
  - can count # of ways to get a sum of sum(1..n)/2 since each set must have half of the total sum
*/

const ll MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  ll MAX_SUM = n*(n+1)/2;

  // simple case: odd max sum can't be split evenly
  if (MAX_SUM & 1) {
    cout << 0 << endl;
    return 0;
  }

  // dp[i][j] = # ways to sum to i using first j numbers [1, i]
  vector<vector<ll>> dp(MAX_SUM/2+1, vector<ll>(n));
  dp[0][0] = 1;

  for (int i = 0; i <= MAX_SUM/2; i++) {
    for (int j = 1; j < n; j++) {
      // jth number is not included
      dp[i][j] = dp[i][j-1];
      if (i - j >= 0) {
        // jth number is included
        dp[i][j] += dp[i-j][j-1];
      }

      dp[i][j] %= MOD;
    }
  }

  // count using only first n-1 elements
  // guarentees that nth element is always placed in second set since first set is created with only first n-1 elements
  cout << dp[MAX_SUM/2][n-1]<< endl;
}