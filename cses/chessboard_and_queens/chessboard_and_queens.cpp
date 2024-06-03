#include <iostream>
#include <vector>
using namespace std;

// brute force backtracking:
// place a queen on each row if its valid and backtrack to count solutions

vector<vector<char>> grid(8, vector<char>(8));
vector<bool> column(8); 
vector<bool> diag1(15);
vector<bool> diag2(15);
int res = 0;

void search(int row) {
  if (row == 8) {
    res++;
    return;
  }

  // try placing queen on all squares in row
  for (int c = 0; c < 8; c++) {
    // check if placing queen is valid
    if (column[c] || diag1[row+c] || diag2[c-row+7] || grid[row][c] == '*') { continue; }

    // place queen
    column[c] = diag1[row+c] = diag2[c-row+7] = true;
    search(row+1);
    // unplace queen (backtrack for next search)
    column[c] = diag1[row+c] = diag2[c-row+7] = false;
  }
}

int main() {
  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      cin >> grid[r][c];
    }
  }

  search(0);

  cout << res;
}