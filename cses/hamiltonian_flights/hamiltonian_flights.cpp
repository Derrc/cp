#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Bitmask DP
*/

const ll MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  // opposite -> adj[i] = nodes that have an outgoing edge to node i
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int start, end;
    cin >> start >> end;
    adj[--end].push_back(--start);
  }

  // dp[i][j] = subset i of cities that are visited ending in city j
  vector<vector<ll>> dp(1<<n, vector<ll>(n));
  // start in city 0
  dp[1][0] = 1;

  for (int s = 1; s < (1<<n); s++) {
    // only consider subsets where city 0 is visited
    if ((s & 1) == 0) { continue; }

    for (int end = 0; end < n; end++) {
      if ((s & (1<<end)) == 0) { continue; }

      for (int city : adj[end]) {
        if ((s & (1<<city)) == 0) { continue; }

        dp[s][end] += dp[s^(1<<end)][city];
        dp[s][end] %= MOD;
      }
    }
  }

  cout << dp[(1<<n)-1][n-1] << endl;
}