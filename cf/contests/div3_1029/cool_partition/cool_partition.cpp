#include <iostream>
#include <set>
using namespace std;

// Partition elements are additive as we create more partitions
// Last partition must contain all distinct elements in the array
// Partition ending at index r must contain all distinct elements from [1, r]

int const maxN = 2e5 + 5;
int a[maxN];
int d[maxN];

void solve() {
  int n;
  cin >> n;

  set<int> distinct;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    distinct.insert(a[i]);
    d[i] = distinct.size();
  }

  set<int> cur;
  int res = 0;
  int l = n-1, r = n-1;
  while (r >= 0) {
    while (cur.size() != d[r]) {
      cur.insert(a[l]);
      l--;
    }

    r = l;
    res++;
    cur.clear();
  }

  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}