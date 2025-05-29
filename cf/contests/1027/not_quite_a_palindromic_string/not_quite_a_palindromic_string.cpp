#include <iostream>
#include <string>
#include <map>
using namespace std;

// To form k good pairs
// Form n-k bad pairs and then check if remaining can form k good pairs
// if remaining count of 1s and 0s are even -> yes

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int cnt[2]{};
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      cnt[c - '0']++;
    }
    
    cnt[0] -= (n / 2) - k;
    cnt[1] -= (n / 2) - k;

    if (cnt[0] < 0 || cnt[1] < 0) {
      cout << "NO" << "\n";
      continue;
    }

    if (cnt[0] % 2 != 0 || cnt[1] % 2 != 0) {
      cout << "NO" << "\n";
      continue;
    }

    cout << "YES" << "\n";
  }

  return 0;
}