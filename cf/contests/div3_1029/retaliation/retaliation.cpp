#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

// Doing a pair of operations is subtracting n+1 from every element
// Thus to explode the array all numbers have to be the same and divisible by n+1
// Now we need to figure out the number of operations k we need other than the pair of ops
// Absolute diff b/w pairs of elements represents k
// After performing k operations of 1 or 2  -> all numbers should be the same and be divisible by n+1

int const maxN = 2e5 + 5;
ll a[maxN];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll diff = -1;
  for (int i = 0; i < n-1; i++) {
    if (i == 0) {
      diff = a[i] - a[i+1];
    }
    else if (a[i] - a[i+1] != diff) {
      cout << "NO" << "\n";
      return;
    }
  }

  ll target = diff > 0 ? a[n-1] : a[0];
  diff = abs(diff);
  if ((target - diff) >= 0 && (target - diff) % (n + 1) == 0) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }

  return;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}