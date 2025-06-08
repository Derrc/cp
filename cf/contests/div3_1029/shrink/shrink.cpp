#include <iostream>
#include <vector>
using namespace std;

int const maxN = 2e5 + 5;
int res[maxN];

void solve() {
  int n;
  cin >> n;
  
  int i = 1;
  int l = 0, r = n-1;
  while (l < r) {
    res[l] = i;
    res[r] = ++i;
    i++;
    l++;
    r--;
  }
  
  if (l == r) {
    res[l] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}