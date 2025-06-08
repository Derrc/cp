#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> doors(n);
  for (int i = 0; i < n; i++) {
    cin >> doors[i];
  }

  int used = false;
  for (int i = 0; i < n; i++) {
    if (doors[i] == 0) { continue; }
    if (doors[i] == 1) {
      if (!used) {
        used = true;
        i += (x-1);
      } else {
        cout << "NO" << "\n";
        return;
      }
    }
  }

  cout << "YES" << "\n";
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