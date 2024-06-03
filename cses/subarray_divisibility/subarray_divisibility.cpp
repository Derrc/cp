#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;

/*
  Keep track of modulo n of prefix sums in a map where (k,v) = (modulo n of prefix sum, count of prefixes with this sum)
  - lets us easily count how many subarrays exist that satisfy a certain condition
  - modulo is distributive under subtraction, search for prefix sums with same modulo as current sum
  - have to deal with negative mod values
*/

int main() {
  int n;

  cin >> n;

  vector<ll> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }


  ll count = 0;
  ll cur_sum = 0;
  unordered_map<ll, ll> map;

  for (int i = 0; i < n; i++) {
    cur_sum += arr[i];

    ll mod = cur_sum % n;

    // count current prefix as subarray
    if (mod == 0) {
      count += 1;
    }
    else if (mod < 0) {
      mod = n + mod;
    }

    count += map[mod];
    map[mod] += 1;
  }
  cout << count;
}
