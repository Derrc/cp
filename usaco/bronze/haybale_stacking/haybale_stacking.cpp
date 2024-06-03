#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
  Prefix sums: adding 1 to range from (a,b) can be represented as prefix sums by adding one to cell at index a and subtracting one to cell at index b
*/

int main() {
  int n, k;

  cin >> n >> k;

  vector<ll> diff(n+1);

  for (int i = 0; i < k; i++) {
    ll start, end;
    cin >> start >> end;

    diff[start] += 1;
    if (end+1 <= n) {
      diff[end+1] -= 1;
    }
  }

  vector<ll> haybales(n+1);

  for (int i = 1; i <= n; i++) {
    haybales[i] = diff[i] + haybales[i-1];
  }

  sort(haybales.begin(), haybales.end());

  cout << haybales[n / 2 + 1];
}