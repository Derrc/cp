#include <iostream>
#include <cstring>
using namespace std;

// A match at index i can create at least i matches
// Find the rightmost index that can match
// Numbers can be set diagonally
// - a[i] can be set to any a[j] where i % 2 == j % 2
// - a[i] can be set to any b[j] where i % 2 != j % 2
// But since we can remove i+1 beforehand, we can match any value [i+2, n] along with b[i+1]
// Only a[i+1] can't be set since we removed it
// All of this generalizes to b as well

int const maxN = 2e5 + 5;
int a[maxN];
int b[maxN];
bool seen[maxN];

void solve() {
  int n;
  cin >> n;

  memset(seen, false, sizeof(seen));

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  if (a[n-1] == b[n-1]) {
    cout << n << "\n";
    return;
  }

  int res = 0;
  for (int i = n-2; i >= 0; i--) {
    if (a[i] == b[i] || a[i] == a[i+1] || b[i] == b[i+1] || seen[a[i]] || seen[b[i]]) {
      res = i+1;
      break;
    }
    seen[a[i+1]] = seen[b[i+1]] = true;
  }

  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  
  return 0;
}