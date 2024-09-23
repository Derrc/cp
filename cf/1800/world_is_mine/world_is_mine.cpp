#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
  DP
  - dp[i][j] = # of blocked cakes if Alice is eating cake i with j extra steps remaining
  - in order to block cake i if Alice is eating cake j, i-j+rem >= cnt(i)
  - store inputs as compressed freq array (only order matters not value)
*/

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      cnt[x]++;
    }

    vector<int> a;
    for (auto &[k, v] : cnt) {
      a.push_back(v);
    }

    int k = a.size();
    vector<vector<int>> dp(k, vector<int>(k));


  }
}