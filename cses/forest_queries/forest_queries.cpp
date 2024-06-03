#include <iostream>
#include <vector>
using namespace std;

/*
  2D prefix sums:
  1. Calculating 2d prefix array:
    - arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] (overlap) + arr[i][j]
  2. Calculating submatrix from rows a to A and cols b to B
    - arr[a to A][b to B] = arr[A][B] - arr[a-1][B] - arr[A][b-1] + arr[a-1][b-1] (overlap)
*/

int main() {
  int n, q;

  cin >> n >> q;

  vector<vector<int>> prefix(n+1, vector<int>(n+1));

  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) {
      char next;
      cin >> next;

      prefix[r][c] = prefix[r-1][c] + prefix[r][c-1] - prefix[r-1][c-1];
      prefix[r][c] += 1 ? next == '*' : 0;
    }
  }

  for (int i = 0; i < q; i++) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    int trees = prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1];
    cout << trees << "\n";
  }
}