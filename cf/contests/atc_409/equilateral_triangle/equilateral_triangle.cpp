#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// Simulate placing points on a circle and keep track of counts in each point [0, circumference-1]
// Equilateral triangle = cnt[i] * cnt[i + (circumference / 3)] * cnt[i + 2 * (circumference / 3)]

int const maxN = 3e5 + 5;
int circle[maxN]{};
int d[maxN]{};

int main() {
  int n, l;
  cin >> n >> l;

  for (int i = 0; i < n-1; i++) {
    cin >> d[i];
  }

  if (l % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  int cur = 0;
  circle[0] = 1;
  for (int i = 0; i < n-1; i++) {
    cur = (cur + d[i]) % l;
    circle[cur]++;
  }

  ll res = 0;
  for (int i = 0; i < l / 3; i++) {
    res += 1ll * circle[i] * circle[i + (l / 3)] * circle[i + 2 * (l / 3)];
  }

  cout << res << endl;
}