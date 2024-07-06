#include <iostream>
#include <vector>
using namespace std;

/*
  DP
  - MEX is strictly non-increasing as deletes occur
  - only care until MEX = 0, subsequent deletes won't add to total sum
*/

const int MAX_N = 5003;
const int INF = INT32_MAX;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> freq(MAX_N);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x < n) {
        freq[x]++;
      }
    }
    // get initial MEX(a)
    int m = 0;
    while (freq[m]) { m++; }
    // dp[i] = cur sum when MEX(a) = i
    vector<int> dp(MAX_N, INF);
    dp[m] = 0;
    for (int i = m; i >= 1; i--) {
      for (int j = 0; j < i; j++) {
        dp[j] = min(dp[j], dp[i] + i * (freq[j] - 1) + j);
      }
    }

    cout << dp[0] << "\n";
  }

}