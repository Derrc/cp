#include <iostream>
#include <vector>
using namespace std;

/*
  DFS/Prefix Sums
  - rows and cols problem is the same
  - each component contributes size s cells to any row from [r_min-1, r_max+1]
*/

int n, m;
int min_r, max_r, min_c, max_c, sz;
vector<vector<char>> g;
vector<vector<bool>> vis;
// prefix sums 1-indexed
vector<int> R, C, freeR, freeC;

void dfs(int r, int c) {
  if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] == '.' || vis[r][c]) return;

  vis[r][c] = true;
  sz++;
  min_r = min(min_r, r);
  max_r = max(max_r, r);
  min_c = min(min_c, c);
  max_c = max(max_c, c);

  dfs(r+1, c);
  dfs(r-1, c);
  dfs(r, c+1);
  dfs(r, c-1);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    g.assign(n+5, vector<char>(m+5, ' '));
    vis.assign(n+5, vector<bool>(m+5, false));
    R.assign(n+5, 0);
    C.assign(m+5, 0);
    freeR.assign(n+5, 0);
    freeC.assign(m+5, 0);

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        cin >> g[r][c];

        if (g[r][c] == '.') {
          freeR[r]++;
          freeC[c]++;
        }
      }
    }

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        if (vis[r][c] || g[r][c] == '.') continue;

        sz = 0;
        min_r = n-1;
        max_r = 0;
        min_c = m-1;
        max_c = 0;

        dfs(r, c);

        // expand by +1, -1
        min_r = max(min_r-1, 0);
        max_r = min(max_r+1, n-1);
        min_c = max(min_c-1, 0);
        max_c = max(max_c+1, m-1);

        R[min_r+1] += sz;
        R[max_r+2] -= sz;
        C[min_c+1] += sz;
        C[max_c+2] -= sz;
      }
    }

    int res = 0;
    for (int r = 1; r <= n; r++) {
      R[r] += R[r-1];
      res = max(res, R[r] + freeR[r-1]);
    }

    for (int c = 1; c <= m; c++) {
      C[c] += C[c-1];
      res = max(res, C[c] + freeC[c-1]);
    }

    cout << res << "\n";
  }
}