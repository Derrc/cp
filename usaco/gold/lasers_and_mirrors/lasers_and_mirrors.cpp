#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

/*
  0-1 BFS shortest path through graph
  - can either travel vertical or horizontal from each fence post
  - shorter: processing neighbors checks entire line (x or y) can just do normal bfs since end will be marked if its in current line
*/

const int inf = INT32_MAX;

struct Point {
  int x, y;
};

int main() {
  freopen("lasers.in", "r", stdin);
  freopen("lasers.out", "w", stdout);

  int n;
  cin >> n;
  n += 2;

  // start in points[0] and end in points[1]
  vector<Point> points(n);
  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
  }

  // lines[0] = x coords, lines[1] = y coords
  unordered_map<int, vector<int>> lines[2];
  for (int i = 0; i < n; i++) {
    lines[0][points[i].x].push_back(i);
    lines[1][points[i].y].push_back(i);
  }

  deque<pair<int, int>> q = {{0, 0}, {0, 1}}; // 0 = horizontal, 1 = vertical
  vector<int> dist(n, inf);
  dist[0] = 0;
  while (!q.empty()) {
    auto [cur, dir] = q.front();
    q.pop_front();

    int coord = dir ? points[cur].y : points[cur].x;
    for (int nxt : lines[dir][coord]) {
      if (dist[nxt] != inf) { continue; }

      dist[nxt] = dist[cur]+1;
      q.push_back({nxt, !dir});
    }

    // 0-1 bfs
    // for (int nx : lines[0][points[cur].x]) {
    //   int w = dir != 0;
    //   if (dist[cur]+w < dist[nx]) {
    //     dist[nx] = dist[cur]+w;

    //     // 0-edge, no mirror
    //     if (w == 0) {
    //       q.push_front({nx, 0});
    //     } else {
    //       q.push_back({nx, 0});
    //     }
    //   }
    // }

    // for (int ny : lines[1][points[cur].y]) {
    //   int w = dir != 1;
    //   if (dist[cur]+w < dist[ny]) {
    //     dist[ny] = dist[cur]+w;
        
    //     if (w == 0) {
    //       q.push_front({ny, 1});
    //     } else {
    //       q.push_back({ny, 1});
    //     }
    //   }
    // }
  }

  cout << (dist[1] == inf ? -1 : dist[1]-1) << endl;  
}