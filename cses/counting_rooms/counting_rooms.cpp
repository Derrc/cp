#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<char>> grid(rows, vector<char>(cols));
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      cin >> grid[r][c];
    }
  }

  vector<vector<bool>> visited(rows, vector<bool>(cols));
  int count = 0;

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (grid[r][c] == '#' || visited[r][c]) { continue; }

      count++;
      deque<pair<int, int>> stack = {{r, c}};
      visited[r][c] = true;
      while (!stack.empty()) {
        pair<int, int> cur = stack.back();
        stack.pop_back();

        for (pair<int, int> &dir : directions) {
          int newr = cur.first+dir.first;
          int newc = cur.second+dir.second;
          if (0 <= newr && newr < rows && 0 <= newc && newc < cols && grid[newr][newc] == '.' && !visited[newr][newc]) {
            stack.push_back({newr, newc});
            visited[newr][newc] = true;
          }
        }
      }

    }
  }

  cout << count;
  
}