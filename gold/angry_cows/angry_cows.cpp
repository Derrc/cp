#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  Binary search for power R and drop position x
  - O(n) time to simulate power R on position x
  - O(nlogn) time to binary search on position x that detonates all haybales for a given power R
  - O(n(logn)^2) time to binary search for minimum power R
*/

int n;
vector<int> haybales;

// simulate explosion on given position with given power
// we can reach all haybales if both left and right pointers reach first and last index
bool explode(int position, int power) {
  int l, r, position_l, position_r;
  l = r = position_l = position_r = position;

  while (power > 0 && (0 <= l || r < n)) {
    while (l >= 0 && haybales[position_l] - haybales[l] <= power) {
      l--;
    }

    while (r < n-1 && haybales[r] - haybales[position_r] <= power) {
      r++;
    }

    position_l = l+1;
    position_r = r-1;
    power--;
  }

  return position_l == 0 && position_r == n-1;
}

int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  cin >> n;

  haybales.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> haybales[i];
  }

  sort(haybales.begin(), haybales.end());

  cout << explode(2, 5);
}