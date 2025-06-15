#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<int, int> cnt;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int b = a[i] % 200;
    res += cnt[b];
    cnt[b]++;
  }

  cout << res << endl;
}