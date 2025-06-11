#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// elements >= x have to appear >= x times
// if an array has all numbers >= len(array) = n -> then elements >= n appear n times

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  for (int i = n; i > 0; i--) {
    if (a[i-1] >= i) {
      cout << i << endl;
      return 0;
    }
  }

  cout << 0 << endl;
}