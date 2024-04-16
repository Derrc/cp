#include <iostream>
#include <vector>
using namespace std;

/*
  Classic Knapsack DP: weights, values with constraint on total weight
  - dp[x][k] = max pages with a price constraint of x using a combination of the first k books
  - choose to either include kth book as part of solution set, or don't include it
  - dp[x][k] = max(dp[x-prices(k)][k-1] + pages(k), dp[x][k-1])
*/

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> prices(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> prices[i];
  }

  vector<int> pages(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> pages[i];
  }

  vector<vector<int>> dp(n+1, vector<int>(x+1));
  // k = first k books, p = current price constraint
  for (int k = 1; k <= n; k++) {
    for (int p = 1; p <= x; p++) {
      // if kth book is not part of solution
      dp[k][p] = dp[k-1][p];
      if (p - prices[k] >= 0) {
        // if kth book is part of solution
        dp[k][p] = max(dp[k][p], dp[k-1][p - prices[k]] + pages[k]);
      }
    }
  }

  cout << dp[n][x] << endl;
}