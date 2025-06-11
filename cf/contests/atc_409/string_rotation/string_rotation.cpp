#include <iostream>
#include <string>
using namespace std;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int l = -1;
  for (int i = 1; i < n; i++) {
    if (s[i-1] > s[i]) {
      l = i-1;
      break;
    }
  }

  if (l == -1) {
    cout << s << "\n";
    return;
  }

  int r = n;
  for (int i = l+1; i < n; i++) {
    if (s[l] < s[i]) {
      r = i;
      break;
    }
  }

  string res = s.substr(0, l) + s.substr(l+1, r-l-1) + s.substr(l, 1);

  if (r < n) {
    res += s.substr(r);
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