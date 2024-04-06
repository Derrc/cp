#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

/*
  Binary search for power R and drop position x
  - O(n) time to simulate power R on position x
  - O(nlogn) time to binary search on position x that detonates all haybales for a given power R
    - get maximum position that will detonate all haybales to the left, if this position doesn't detonate all to the right, one doesn't exist
  - O(n(logn)^2) time to binary search for minimum power R
*/

int MAX_POS = 2e9;

int n;
vector<int> haybales;

// check if explosion can reach leftmost haybale
bool explode_l(int pos, int power) {
  int l = lower_bound(haybales.begin(), haybales.end(), pos) - haybales.begin() - 1;

  while (power > 0 && l >= 0) {
    // can't reach next haybale
    if (pos - haybales[l] > power) { return false; }
    // detonate all reachable haybales
    while (l >= 0 && pos - haybales[l] <= power) {
      l--;
    }

    // move new position to furthest detonated haybale
    pos = haybales[l+1];
    power -= 2;
  }

  return l < 0;
}

// check if explosion can reach rightmost haybale
bool explode_r(int pos, int power) {
  int r = upper_bound(haybales.begin(), haybales.end(), pos) - haybales.begin();

  while (power > 0 && r < n) {
    if (pos - haybales[r] > power) { return false; }
    while (r < n && haybales[r] - pos <= power) {
      r++;
    }

    pos = haybales[r-1];
    power -= 2;
  }

  return r >= n;
}

// binary search for minimum power
int binary_search() {
  int pow_lo = 0;
  int pow_hi = MAX_POS;
  while (pow_lo < pow_hi) {
    int power = pow_lo + (pow_hi - pow_lo) / 2;

    // binary search for maximum position that explodes leftmost haybale
    int pos_lo = 0;
    int pos_hi = MAX_POS;
    while (pos_lo < pos_hi) {
      int pos = pos_lo + (pos_hi - pos_lo + 1) / 2;
      if (explode_l(pos, power)) {
        pos_lo = pos;
      } else {
        pos_hi = pos-1;
      }
    }

    // check if we can also explode rightmost haybale
    if (explode_r(pos_lo, power)) {
      pow_hi = power;
    } else {
      pow_lo = power+1;
    }
  }

  return pow_hi;
}

int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  cin >> n;

  haybales.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> haybales[i];
    // scale by 2 to eliminate chance of rounding errors with floating point numbers
    haybales[i] *= 2;
  }

  sort(haybales.begin(), haybales.end());

  cout << fixed << setprecision(1) << (double)binary_search() / 2;
}