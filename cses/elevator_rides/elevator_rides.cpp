#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Bitmask DP
  - to calculate dp[i], for each weight (wi) in subset, we can check if adding wi adds to the last group with (S / wi) or if it creates a new group
*/

int main() {
  int n, x;
  cin >> n >> x;

  vector<ll> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> weights[i];
  }

  // dp[i : {min, last}] = min: min rides with subset i, last: weight of last group with subset i
  vector<pair<ll, ll>> dp(1<<n);
  dp[0] = {1, 0};

  for (int s = 1; s < (1<<n); s++) {
    // initial value
    dp[s] = {n, 0};
    for (int w = 0; w < n; w++) {
      if ((s & (1<<w)) == 0) { continue; }

      pair<ll, ll> prev = dp[s^(1<<w)];

      // last(S/wi) + weight[w] <= limit
      if (prev.second + weights[w] <= x) {
        prev.second += weights[w];
      } else {
        // new group
        prev.first++;
        prev.second = weights[w];
      }
      
      // compares min rides then weight of last group
      dp[s] = min(dp[s], prev);
    }
  }

  cout << dp[(1<<n)-1].first << endl;
}