#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

// Calculate the rectangle needed when we remove each monster
// The only monsters that affect the rectangle are ones that have the min/max x/y coordinates
// Keep track of max, 2nd max, min, and 2nd min so that we can adjust the rectangle for these monsters

struct MinMax {
  ll mn, mx, mn2, mx2;

  void add(int x) {
    if (x < mn) {
      mn2 = mn;
      mn = x;
    }
    else if (x < mn2) {
      mn2 = x;
    }
    
    if (x > mx) {
      mx2 = mx;
      mx = x;
    }
    else if (x > mx2) {
      mx2 = x;
    }
  }

  ll segment(int x) {
    ll curMn = mn;
    ll curMx = mx;
    if (x == curMn) { curMn = mn2; }
    if (x == curMx) { curMx = mx2; }

    return curMx - curMn + 1;
  }

  void print() {
    cout << mn << " " << mn2 << " " << mx << " " << mx2 << "\n";
  }
};

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);

    MinMax xMinMax = {INT64_MAX, 0, INT64_MAX, 0};
    MinMax yMinMax = {INT64_MAX, 0, INT64_MAX, 0};
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
      xMinMax.add(x[i]);
      yMinMax.add(y[i]);
    }
    
    // have to select at least 1 rectangle (cell)
    if (n < 2) {
      cout << 1 << "\n";
      continue;
    }

    ll minArea = INT64_MAX;
    for (int i = 0; i < n; i++) {
      ll xLen = xMinMax.segment(x[i]);
      ll yLen = yMinMax.segment(y[i]);

      if (xLen * yLen == n-1) {
        minArea = min(minArea, min((xLen + 1) * yLen, xLen * (yLen + 1)));
      } else {
        minArea = min(minArea, xLen * yLen);
      }
    }

    cout << minArea << "\n";
  }
  
  return 0;
}