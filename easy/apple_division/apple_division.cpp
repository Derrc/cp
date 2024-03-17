#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// brute force recursion:
// try all possible combinations of 2 subsets that include all apples by keeping track of sums in both sets
// at each recursion step add current element to both sum of first and second set

// bitmasks:
// we can iterate through sets by using bit representation of numbers from 2^(N-1) -> 0
// this will contain N bits, each bit i will represent whether apple[i] is in set 1 or set 2
// 1 << x = 2^x (left shift)
// mask & (1 << x) = whether bit x is turned on (zero-indexed left to right)

int n;
vector<ll> apples;

ll recurse(int index, ll sum1, ll sum2) {
  if (index == n) { return abs(sum1 - sum2); }

  int weight = apples[index];
  return min(recurse(index+1, sum1+weight, sum2), recurse(index+1, sum1, sum2+weight));
}

int main() {
  cin >> n;
  apples.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> apples[i];
  }

  ll ans = INT64_MAX;
  // iterate over possible subsets
  for (int mask = 0; mask < (1 << n); mask++) {
    ll sum1 = 0;
    ll sum2 = 0;
    
    // check whether each bit is on or off
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) { sum1 += apples[i]; }
      else { sum2 += apples[i]; }
    }

    ans = min(ans, abs(sum1 - sum2));
  }

  cout << ans;  
}