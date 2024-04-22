#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  // dp[i][j] = min edits with first i chars from s1 to first j chars from s2
  vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));

  // initialize base case: if s2 is empty -> len(s1) edits, vice versa
  for (int i = 0; i <= s1.size(); i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= s2.size(); j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        // replace ith ch with jth, delete ith ch, insert jth ch
        dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
      }
    }
  }

  cout << dp[s1.size()][s2.size()] << endl;
}