#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

/*
  2 sweeps testing all possible vertical and horizontal line splits of two enclosures
  - compute min and max prefix and suffix arrays on both sides of the line to perform min/max queries easily
  - we already have min and max values of x since we are testing vertical splits, need to just keep track of min and max values of y
  - testing horizontal splits is same as testing vertical with x and y coords swapped
*/

int n;
vector<pair<int, int>> points;

ll search() {
  sort(points.begin(), points.end());

  // min and max values
  vector<pair<int, int>> prefix(n);
  vector<pair<int, int>> suffix(n);
  prefix[0] = {points[0].second, points[0].second};
  suffix[n-1] = {points[n-1].second, points[n-1].second};

  for (int i = 1; i < n; i++) {
    prefix[i].first = min(prefix[i-1].first, points[i].second);
    prefix[i].second = max(prefix[i-1].second, points[i].second);
  }

  for (int i = n-2; i >= 0; i--) {
    suffix[i].first = min(suffix[i+1].first, points[i].second);
    suffix[i].second = max(suffix[i+1].second, points[i].second);
  }

  int min_x = points[0].first;
  int max_x = points[n-1].first;

  ll one_area = (ll)(max_x - min_x) * (prefix[n-1].second - prefix[n-1].first);
  ll min_area = INT64_MAX;

  // test splits
  for (int i = 0; i < n-1; i++) {
    // can't split if both points are the same x value
    if (points[i].first != points[i+1].first) {
      ll rect1 = (ll)(points[i].first - min_x) * (prefix[i].second - prefix[i].first);
      ll rect2 = (ll)(max_x - points[i+1].first) * (suffix[i+1].second - suffix[i+1].first);

      min_area = min(min_area, rect1 + rect2);
    }
  }

  return one_area - min_area;
}

int main() {
  freopen("split.in", "r", stdin);
  freopen("split.out", "w", stdout);

  cin >> n;

  points.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> points[i].first >> points[i].second;
  }

  ll best = 0;

  best = max(best, search());

  for (int i = 0; i < n; i++) {
    swap(points[i].first, points[i].second);
  }

  best = max(best, search());

  cout << best;
}