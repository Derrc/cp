#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
  2D prefix sums, coordinate compression
  - can count number of subsets by iterating through all unique pairs of coordinates and counting:
  - pair rectangle + rectangles made from expanding pair rectangle top and lower y-bound = (a+1)(b+1) rectangles where a = # of points above and b = # of points below)
  - (greater than prefix array) arr[i][j] = # of points where y-coordinate at i is less than y-coordinates from points in range from x = 0 to x = j
*/

typedef struct pair<int, int> Point;

bool ycmp(const Point &p1, const Point &p2) {
  return p1.second < p2.second;
}

int main() {
  int n;

  cin >> n;

  vector<Point> points(n);

  for (int i = 0; i < n; i++) {
    Point p;
    cin >> p.first >> p.second;
    points[i] = p;
  }

  // coordinate compression
  sort(points.begin(), points.end());
  for (int i = 0; i < n; i++) {
    points[i].first = i;
  }

  sort(points.begin(), points.end(), ycmp);
  for (int i = 0; i < n; i++) {
    points[i].second = i;
  }

  sort(points.begin(), points.end());

  // get 2d prefix sum arrays greater than and less than a y-coordinate
  vector<vector<ll>> gt(n, vector<ll>(n+1));
  vector<vector<ll>> lt(n, vector<ll>(n+1));

  for (int i = 0; i < n; i++) {
    int y = points[i].second;
    for (int x = 1; x <= n; x++) {
      gt[y][x] = gt[y][x-1] + (points[x-1].second > y);
      lt[y][x] = lt[y][x-1] + (points[x-1].second < y);
    }
  }

  ll subsets = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int top = max(points[i].second, points[j].second);
      int bottom = min(points[i].second, points[j].second);

      subsets += (1 + gt[top][j+1] - gt[top][i+1]) * (1 + lt[bottom][j+1] - lt[bottom][i+1]);
    }
  }

  // add boxes with 1 point (always possible since unique x and y values for each coordinate) and empty set
  cout << subsets + n + 1;
}