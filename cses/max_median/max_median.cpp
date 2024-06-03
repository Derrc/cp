#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
  Binary search for max value that satisfies function
*/

int n;
int k;
vector<ll> arr;

// checks if it is possible to create median = target given k operations
// each number in [n/2, n) will have to equal target
bool check(ll target) {
  ll operations = 0;
  for (int i = n/2; i < n; i++) {
    operations += max((ll)0, target - arr[i]);
  }

  return operations <= k;
}

int binary_search(ll lo, ll hi) {
  // if entire range is false return lo-1
  lo--;

  // interval jumping
  // ll cur = lo;
  // for (ll jump = (lo+hi)/2; jump >= 1; jump /= 2) {
  //   while (check(cur+jump)) {
  //     cur += jump;
  //   }
  // }

  // return cur;

  // traditional binary search
  while (lo < hi) {
    // fine in maximum case but in normal bs and min case
    // avoids rounding up when bounds are negative (vs. (lo+hi)/2)
    int mid = (lo+hi+1) / 2;
    if (check(mid)) {
      lo = mid;
    } else{
      hi = mid-1;
    }
  }

  return lo;
}

int main() {
  cin >> n >> k;

  arr.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  cout << binary_search(arr[n/2], INT32_MAX);
}