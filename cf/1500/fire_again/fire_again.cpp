#include <iostream>
#include <deque>
using namespace std;
using pii = pair<int, int>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool vis[2005][2005]{};

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  pii res;
  deque<pii> q;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    q.push_back({x, y});
    vis[x][y] = true;
    res = {x, y};
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop_front();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx > 0 && nx <= m && ny > 0 && ny <= n && !vis[nx][ny]) {
        q.push_back({nx, ny});
        res = {nx, ny};
        vis[nx][ny] = true;
      }
    }
  }

  cout << res.first << " " << res.second << endl;

  return 0;
}