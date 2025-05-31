#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <deque>
using namespace std;
using pii = pair<int, int>;

// Try to solve the quesion using all given information
// We know that any point with at least 1 free neighbor will have a closest point of distance 1
// Start a BFS from these points and visit all other points
// Any visited point will share the same closest coordinate as the previous point

int const maxN = 200005;
int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0, 1, 0, -1};

pii p[maxN];

int main() {
  int n;
  cin >> n;

  map<pii, pii> res;
  set<pii> pSet;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
    pSet.insert({x, y});
  }

  deque<pii> q;
  for (int i = 0; i < n; i++) {
    auto [x, y] = p[i];
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      
      if (!pSet.count({nx, ny})) {
        q.push_back({x, y});
        res[{x, y}] = {nx, ny};
        break;
      }
    }
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop_front();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (pSet.count({nx, ny}) && !res.count({nx, ny})) {
        q.push_back({nx, ny});
        res[{nx, ny}] = res[{x, y}];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    auto [x, y] = p[i];
    cout << res[{x, y}].first << " " << res[{x, y}].second << "\n";
  }

  return 0;
}