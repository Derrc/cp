#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

/*
  Floodfill: calculate area and perimeter for each connected component
*/

struct Cell {
  int r, c;
};

vector<Cell> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);

  int n;
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cin >> grid[r][c];
    }
  }

  vector<vector<bool>> visited(n, vector<bool>(n));
  // max (area, perimeter)
  pair<ll, ll> best;

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      if (grid[r][c] == '.' || visited[r][c]) { continue; }

      deque<Cell> q = {Cell{r, c}};
      visited[r][c] = true;
      ll area = 0;
      ll perimeter = 0;

      while (!q.empty()) {
        Cell cur = q.front();
        q.pop_front();

        area++;

        for (Cell dir : directions) {
          int newr = cur.r+dir.r;
          int newc = cur.c+dir.c;
          if (0 <= newr && newr < n && 0 <= newc && newc < n && !visited[newr][newc] && grid[newr][newc] == '#') {
            q.push_back({newr, newc});
            visited[newr][newc] = true;
          }
          if (newr < 0 || newr >= n || newc < 0 || newc >=n || grid[newr][newc] == '.') {
            perimeter++;
          }
        }
      }

      if (area > best.first) {
        best.first = area;
        best.second = perimeter;
      }
      else if (area == best.first) {
        best.second = min(best.second, perimeter);
      }
    }
  }

  cout << best.first << " " << best.second;
}