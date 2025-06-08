#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int len = 1;
      while (i + 1 < n) {
        if (a[i] + 1 == a[i+1]) {
          len++;
          i++;
        } else if (a[i] == a[i+1]) {
          i++;
        } else {
          break;
        }
      }

      if (len == 1) {
        cnt++;
      } else {
        cnt += ceil((double)len / 2);
      }
    }

    cout << cnt << "\n";
  }

  return 0;
}