#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  Binary search number of elements between two intervals in sorted array
  - O(Qlogn)
*/

vector<int> haybales;

// returns index of first element greater than or equal to target
int binary_search_min(int lo, int hi, int target) {
  // if target is greater than haybales[hi] then return n+1
  hi++;

  while (lo < hi) {
    int mid = (lo+hi) / 2;
    if (haybales[mid] < target) {
      lo = mid+1;
    } else {
      hi = mid;
    }
  }

  return hi;
}

// returns index of first element less than or equal to target
int binary_search_max(int lo, int hi, int target) {
  // if target is less than haybales[0] then return -1;
  lo--;

  while (lo < hi) {
    int mid = (lo+hi+1) / 2;
    if (haybales[mid] > target) {
      hi = mid-1;
    } else {
      lo = mid;
    }
  }

  return lo;
}

int main() {
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  haybales.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> haybales[i];
  }

  sort(haybales.begin(), haybales.end());

  for (int i = 0; i < q; i++) {
    int start, end;
    cin >> start >> end;

    // binary search
    int lower_b = binary_search_min(0, n-1, start);
    int upper_b = binary_search_max(0, n-1, end);

    if (lower_b == -1 || upper_b == n+1) {
      cout << 0;
    } else {
      cout << upper_b - lower_b + 1 << "\n";
    }
  }
}

