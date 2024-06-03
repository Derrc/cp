#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  // x+1 is impossible since you need x $1 coins to make x
  vector<int> dp(x + 1, x+1);
  dp[0] = 0;

  for (int i = 1; i <= x; i++) {
    for (int c = 0; c < n; c++) {
      if (i - coins[c] >= 0) {
        dp[i] = min(dp[i], dp[i - coins[c]] + 1);
      }
    }
  }

  cout << (dp[x] == x+1 ? -1 : dp[x]) << endl;
}