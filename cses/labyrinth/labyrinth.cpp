#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// 0 = Down, 1 = Up, 2 = Right, 3 = Left
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<char> step = {'D', 'U', 'R', 'L'};

int main() {
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<char>> grid(rows, vector<char>(cols));
  pair<int, int> start, end;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      cin >> grid[r][c];

      if (grid[r][c] == 'A') { start = {r, c}; }
      else if (grid[r][c] == 'B') { end = {r, c}; }
    }
  }

  vector<vector<int>> distances(rows, vector<int>(cols, INT32_MAX));
  distances[start.first][start.second] = 0;
  vector<vector<int>> parent(rows, vector<int>(cols));
  deque<pair<int, int>> q = {start};

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    int r = cur.first, c = cur.second;
    q.pop_front();

    for (int i = 0; i < 4; i++) {
      int new_r = r+dx[i], new_c = c+dy[i];
      if (new_r < 0 || new_r >= rows || new_c < 0 || new_c >= cols || grid[new_r][new_c] == '#' || distances[new_r][new_c] != INT32_MAX) {
        continue;
      }

      distances[new_r][new_c] = distances[r][c]+1;
      parent[new_r][new_c] = i;
      q.push_back({new_r, new_c});
    }
  }

  if (distances[end.first][end.second] != INT32_MAX) {
    cout << "YES" << "\n" << distances[end.first][end.second] << "\n";

    vector<char> path;
    pair<int, int> cur = end;
    while (cur != start) {
      int dir = parent[cur.first][cur.second];
      // backtrack
      cur.first = cur.first-dx[dir];
      cur.second = cur.second-dy[dir];
      path.push_back(step[dir]);
    }

    reverse(path.begin(), path.end());
    for (char c : path) { cout << c; }
  } else {
    cout << "NO" << endl;
  }
}