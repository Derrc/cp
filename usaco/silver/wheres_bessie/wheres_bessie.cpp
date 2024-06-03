#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
  Floodfill using brute force
  - brute force all possible PCLs into an array
  - only count PCLs that are not a subset of any other PCL
*/

// represents a PCL (top left (r1,c1) and bottom right (r2,c2))
struct PCL {
  int r1, c1, r2, c2;

  bool contains(PCL other) {
    return r1 <= other.r1 && other.r2 <= r2 && c1 <= other.c1 && other.c2 <= c2;
  }
};

vector<vector<char>> grid;
vector<vector<bool>> visited;
map<char, int> counts;
vector<PCL> pcls;

void floodfill(int r, int c, PCL pcl, char ch) {
  if (r < pcl.r1 || r > pcl.r2 || c < pcl.c1 || c > pcl.c2 || visited[r][c] || grid[r][c] != ch) { return; }

  visited[r][c] = true;

  floodfill(r-1, c, pcl, ch);
  floodfill(r+1, c, pcl, ch);
  floodfill(r, c-1, pcl, ch);
  floodfill(r, c+1, pcl, ch);
}

bool is_pcl(PCL pcl) {
  int colors = 0;
  bool one_region = false;
  bool two_or_more_regions = false;
  for (auto it = counts.begin(); it != counts.end(); it++) {
    int count = it->second;
    if (count == 0) { continue; }

    colors++;
    if (count == 1) { one_region = true; }
    else if (count > 1) { two_or_more_regions = true; }
  }

  return colors == 2 && one_region && two_or_more_regions;
}

int main() {
  freopen("where.in", "r", stdin);
  freopen("where.out", "w", stdout);

  int n;
  cin >> n;

  grid.resize(n, vector<char>(n));
  visited.resize(n, vector<bool>(n));

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cin >> grid[r][c];
    }
  }

  for (int r1 = 0; r1 < n; r1++) {
    for (int c1 = 0; c1 < n; c1++) {
      for (int r2 = 0; r2 < n; r2++) {
        for (int c2 = 0; c2 < n; c2++) {
          if (r1 == r2 && c1 == c2) { continue; }
          // reset visited and counts map
          fill(visited.begin(), visited.end(), vector<bool>(n));
          counts.clear();

          PCL cur = {r1, c1, r2, c2};

          // floodfill on current PCL area
          for (int r = r1; r <= r2; r++) {
            for (int c = c1; c <= c2; c++) {
              if (!visited[r][c]) {
                char ch = grid[r][c];
                floodfill(r, c, cur, ch);
                counts[ch] += 1;
              }
            }
          }

          // check if pcl is valid
          if (is_pcl(cur)) { pcls.push_back(cur); }
        }
      }
    }
  }

  int valid_pcls = 0;
  for (int p1 = 0; p1 < pcls.size(); p1++) {
    bool valid = true;
    for (int p2 = 0; p2 < pcls.size(); p2++) {
      if (p1 == p2) { continue; }

      if (pcls[p2].contains(pcls[p1])) {
        valid = false;
        break;
      }
    }

    valid_pcls += valid;
  }

  cout << valid_pcls;
}