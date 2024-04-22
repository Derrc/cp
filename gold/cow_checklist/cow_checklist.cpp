#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int distance(pair<int, int> c1, pair<int, int> c2) {
  int x1 = c1.first, y1 = c1.second;
  int x2 = c2.first, y2 = c2.second;
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
  freopen("checklist.in", "r", stdin);
  freopen("checklist.out", "w", stdout);

  int h, g;
  cin >> h >> g;

  // 1-index
  vector<pair<int, int>> H(h+1);
  for (int i = 1; i <= h; i++) {
    cin >> H[i].first >> H[i].second;
  }

  vector<pair<int, int>> G(g+1);
  for (int i = 1; i <= g; i++) {
    cin >> G[i].first >> G[i].second;
  }

  // dp[i][j][k] = min energy to visit first i holsteins and first j guernseys given that current cow is (1: holstein, 0: guernsey)
  vector<vector<vector<ll>>> dp(h+1, vector<vector<ll>>(g+1, vector<ll>(2, INT32_MAX)));
  dp[1][0][1] = 0;

  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= g; j++) {
      if (i > 0) {
        // top cell came from holstein
        dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1] + distance(H[i], H[i-1]));
      }

      if (j > 0) {
        // left cell came from guernsey
        dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][0] + distance(G[j], G[j-1]));
      }

      if (i > 0 && j > 0) {
        // top cell came from guernsey
        dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][0] + distance(H[i], G[j]));
        // left cell came from holstein
        dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][1] + distance(G[j], H[i]));
      }
    }
  }

  cout << dp[h][g][1] << endl;
}