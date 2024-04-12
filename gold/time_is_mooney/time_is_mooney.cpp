#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
  Simple DP
  - track movements over 1000 days, contraints on problem tell that past 1000 days, reward will always be negative which means 0 is optimal
*/

const int MAX_T = 1000;

int main() {
  freopen("time.in", "r", stdin);
  freopen("time.out", "w", stdout);

  int n, m, c;
  cin >> n >> m >> c;

  vector<int> money(n);
  for (int i = 0; i < n; i++) {
    cin >> money[i];
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int start, end;
    cin >> start >> end;
    // 0-index
    adj[--start].push_back(--end);
  }

  // dp[i][j] represents max money earned on day i if we end in city j
  vector<vector<int>> dp(MAX_T + 1, vector<int>(n, -1));
  dp[0][0] = 0;

  int max_money = 0;
  for (int d = 0; d < MAX_T; d++) {
    for (int i = 0; i < n; i++) {
      /// current city cannot be reached on this day
      if (dp[d][i] == -1) { continue; }

      for (int neighbor : adj[i]) {
        dp[d + 1][neighbor] = max(dp[d+1][neighbor], dp[d][i] + money[neighbor]);
      }
    }

    max_money = max(max_money, dp[d][0] - c * d * d);
  }

  cout << max_money << endl;
}