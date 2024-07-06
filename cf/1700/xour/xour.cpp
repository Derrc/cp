#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/*
  Bit manipulation
  - if i XOR j < 4, then i and j must have matching bits other than the last two bits
  - create groups that satisfy conditions: items within each group can be swapped
  - for each index, smallest item is chosen from each group
*/

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    map<int, priority_queue<int>> g;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      g[a[i] >> 2].push(-a[i]);
    }

    for (int i = 0; i < n; i++) {
      cout << -g[a[i] >> 2].top() << " ";
      g[a[i] >> 2].pop();
    }

    cout << "\n";
  }
}