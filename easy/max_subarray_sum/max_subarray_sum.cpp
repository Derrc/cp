#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n;

  cin >> n;

  vector<ll> prefix(n+1);

  for (int i = 1; i <= n; i++) {
    ll num;
    cin >> num;
    prefix[i] = num + prefix[i-1];
  }

  ll maxSum = prefix[1];
  ll minPrefix = 0;

  for (int i = 1; i <= n; i++) {
    maxSum = max(maxSum, prefix[i] - minPrefix);
    minPrefix = min(minPrefix, prefix[i]);
  }

  cout << maxSum;
}