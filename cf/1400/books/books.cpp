#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  vector<int> books(n);
  for (int i = 0; i < n; i++) {
    cin >> books[i];
  }

  int res = 0;
  int cur_b = 0, cur_t = 0;
  int l = 0, r = 0;
  while (r < n) {
    cur_t += books[r];
    cur_b++;
    while (cur_t > t) {
      cur_t -= books[l];
      cur_b--;
      l++;
    }

    res = max(res, cur_b);
    r++;
  }

  cout << res << endl;
}