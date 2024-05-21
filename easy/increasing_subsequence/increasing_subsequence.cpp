#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  Longest increasing subsequence
  - slow DP O(n^2)
  - DP + binary search O(nlogn)
*/

const int inf = INT32_MAX;

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  // dp[i] = smallest element in nums that ends a lis of length i
  vector<int> dp(n+1, inf);
  dp[0] = -inf;
  for (int i = 0; i < n; i++) {
    // binary search for nums[i] s.t. dp[l-1] < nums[i] < dp[l]
    int l = upper_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
    if (dp[l-1] < nums[i] && nums[i] < dp[l]) {
      dp[l] = nums[i];
    }
  }

  for (int i = n; i >= 0; i--) {
    if (dp[i] < inf) {
      cout << i << endl;
      break;
    }
  }
}