#include <iostream>
using namespace std;

bool can(int m, int s) {
  return s >= 0 && s <= 9*m;
}

int main() {
  int m, s;
  cin >> m >> s;

  int sum_min = s;
  string res_min;
  for (int i = 0; i < m; i++) {
    // min subtask
    for (int d = 0; d <= 9; d++) {
      if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m-i-1, sum_min-d)) {
        res_min += char('0'+d);
        sum_min -= d;
        break;
      }
    }
  }

  int sum_max = s;
  string res_max;
  for (int i = 0; i < m; i++) {
    // max subtask
    for (int d = 9; d >= 0; d--) {
      if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m-i-1, sum_max-d)) {
        res_max += char('0'+d);
        sum_max -= d;
        break;
      }
    }
  }

  if (res_min.size() != m) {
    cout << -1 << " " << -1 << endl;
  } else {
    cout << res_min << " " << res_max << endl;
  }
}