#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
  Knapsack solution: keep track of minimum summed weight for each summed talent value
  - incorrect since dp does not consider case where minimum summed weight is under threshold but optimal weight is slightly above it
*/

int main() {
  freopen("talent.in", "r", stdin);
  freopen("talent.out", "w", stdout);

  int n, w;
  cin >> n >> w;

  vector<int> weights(n);
  vector<int> talents(n);
  int max_talent = 0;
  for (int i = 0; i < n; i++) {
    cin >> weights[i] >> talents[i];
    max_talent += talents[i];
  }

  // dp[i][j] = min summed weight where talent is up to j removing first i cows
  // vector<vector<int>> dp(n+1, vector<int>(max_talent+1));
  // // initialize as if all cows are part of the set
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j <= max_talent; j++) {
  //     dp[i][j] = INT32_MAX;
  //   }
  // }

  // for (int i = 1; i <= n; i++) {
  //   int weight = weights[i-1];
  //   int talent = talents[i-1];
  //   for (int j = max_talent; j >= 0; j--) {
  //     // ith cow is included
  //     dp[i][j] = dp[i-1][j];

  //     if (j + talent <= max_talent) {
  //       // ith cow is removed
  //       dp[i][j] = min(dp[i][j], dp[i-1][j+talent] - weight);
  //     }
  //   }
  // }

  // dp[i] = min summed weight where talent is i
  vector<int> dp(max_talent+1, INT32_MAX);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    int weight = weights[i];
    int talent = talents[i];
    for (int j = max_talent; j >= 0; j--) {
      if (dp[j] != INT32_MAX && j + talent <= max_talent) {
        // min(ith cow is not included in talent sum, ith cow is included)
        dp[j+talent] = min(dp[j+talent], dp[j] + weight);
      }
    }
  }

  double best_ratio = 0;
  for (int i = 1; i <= max_talent; i++) {
    if (dp[i] >= w) {
      best_ratio = max(best_ratio, (double)i / dp[i]);
    }
  }

  cout << floor(1000 * best_ratio) << endl;
}