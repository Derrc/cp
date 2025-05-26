#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

// BFS to get distance to all free cells
// Greedily choose lexographically smallest available direction to move in thats <= k remaining steps

int n, m, k;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
char dir[4] = {'D', 'L', 'R', 'U'};
char grid[1003][1003];
int dist[1003][1003];

void bfs(pii &s) {
  memset(dist, -1, sizeof(dist));
  dist[s.first][s.second] = 0;

  deque<pii> q;
  q.push_back(s);
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop_front();

    for (int i = 0; i < 4; i++) {
      int nr = r + dy[i];
      int nc = c + dx[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.' && dist[nr][nc] == -1) {
        dist[nr][nc] = dist[r][c] + 1;
        q.push_back({nr, nc});
      }
    }
  }
}

int main() {
  cin >> n >> m >> k;

  pii s;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> grid[r][c];
      if (grid[r][c] == 'X') {
        s = {r, c};
        grid[r][c] = '.';
      }
    }
  }

  if (k & 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  bfs(s);

  string res = "";
  pii cur = s;
  while (k--) {
    bool moved = false;

    for (int i = 0; i < 4; i++) {
      int nr = cur.first + dy[i];
      int nc = cur.second + dx[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.' && dist[nr][nc] <= k) {
        res += dir[i];
        cur = {nr, nc};
        moved = true;
        break;
      }
    }

    if (!moved) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  cout << res << endl;
  return 0;
}