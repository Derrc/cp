#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Implementation heavy..

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector grid(rows, vector<ll>(cols, 0));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> grid[r][c];
        }
    }
}