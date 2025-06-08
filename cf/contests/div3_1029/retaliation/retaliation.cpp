#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int const maxN = 2e5 + 5;
ll a[maxN];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll diff = a[0] - a[1];
  for (int i = 1; i < n-1; i++) {
    if (a[i] - a[i+1] != diff) {
      cout << "NO" << "\n";
      return;
    }
  }

  ll target = diff > 0 ? a[n-1] : a[0];
  diff = abs(diff);

  if (diff > target) {
    cout << "NO" << "\n";
    return;
  }

  if ((target - diff) % (n+1) == 0) {
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