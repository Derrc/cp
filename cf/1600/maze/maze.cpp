#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using pii = pair<int, int>;

// BFS from any cell and visit s-k empty cells, where s is the # of empty cells
// Remaining k empty cells can be transformed since we know s-k cells will still be connected

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void printGrid(vector<vector<bool>> &visited, vector<vector<char>> &grid) {
  for (int r = 0; r < grid.size(); r++) {
    for (int c = 0; c < grid[0].size(); c++) {
      if (grid[r][c] == '.' && !visited[r][c]) {
        grid[r][c] = 'X';
      }
      cout << grid[r][c];
    }
    cout << "\n";
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<char>> grid(n, vector<char>(m));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  deque<pii> q;
  int emptyCells = 0;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> grid[r][c];
      if (grid[r][c] == '.') {
        if (q.empty()) {
          q.push_back({r, c});
          visited[r][c] = true;
        }
        emptyCells++;
      }
    }
  }

  if (emptyCells - k == 1) {
    printGrid(visited, grid);
    exit(0);
  }

  int visitedCells = 1;
  bool done = false;
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop_front();
    
    for (int i = 0; i < 4; i++) {
      int nr = r + dy[i];
      int nc = c + dx[i];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.' && !visited[nr][nc]) {
        visited[nr][nc] = true;
        q.push_back({nr, nc});
        if (++visitedCells == (emptyCells - k)) {
          done = true;
          break;
        }
      }
    }

    if (done) { break; }
  }

  printGrid(visited, grid);
}