#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 53;
int n, m;
char grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};

void floodfill(int r, int c) {
  if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || grid[r][c] == '#') {
    return;
  }

  visited[r][c] = true;
  floodfill(r+1, c);
  floodfill(r-1, c);
  floodfill(r, c+1);
  floodfill(r, c-1);
}

void solve() {
  memset(grid, '.', sizeof(grid));
  memset(visited, 0, sizeof(visited));

  cin >> n >> m;

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> grid[r][c];
    }
  }

  // place walls around B and check for adjacent B,G
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (grid[r][c] == 'B') {
        for (int i = 0; i < 4; i++) {
          int new_r = r+dy[i];
          int new_c = c+dx[i];

          if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m) {
            if (grid[new_r][new_c] == 'G') {
              cout << "No" << "\n";
              return;
            }
            if (grid[new_r][new_c] == '.') {
              grid[new_r][new_c] = '#';
            }
          }
        }
      }
    }
  }

  floodfill(n-1, m-1);

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (grid[r][c] == 'G' && !visited[r][c]) {
        cout << "No" << "\n";
        return;
      }
    }
  }

  cout << "Yes" << "\n";
}



int main() {
  int t;
  cin >> t;

  while (t--) { solve(); }
}