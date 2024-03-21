#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Intro to prefix sums, start inclusive, end exclusive (0-indexed)
*/

int main() {
  int n, q;

  cin >> n >> q;

  vector<ll> arr(n);
  vector<pair<ll, ll>> queries(q);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < q; i++) {
    cin >> queries[i].first;
    cin >> queries[i].second;
  }

  vector<ll> prefix_sums(n);
  prefix_sums[0] = arr[0];

  for (int i = 1; i < n; i++) {
    prefix_sums[i] = prefix_sums[i-1] + arr[i];
  }

  for (int i = 0; i < q; i++) {
    ll start = queries[i].first;
    ll end = queries[i].second;

    if (start == 0) {
      cout << prefix_sums[end-1] << "\n";
    } else {
      cout << prefix_sums[end-1] - prefix_sums[start-1] << "\n";
    }
  }
}