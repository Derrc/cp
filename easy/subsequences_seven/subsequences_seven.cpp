#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;

/*
  Using prefix modulo (distributive under addition)
  - no need to keep prefix mods in memory since we only need to access previous mod so we can keep track of it in a var
  - have a vector that keeps track of first time we see every modulo value -> this will be correspond to the largest subarrays
*/

int main() {
  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);

  int n;
  cin >> n;

  vector<ll> ids(n);
  for (int i = 0; i < n; i++) {
    cin >> ids[i];
  }

  // keeps track of first time we encounter mod value as index
  vector<int> first(n, -1);
  // case where mod is 0, we can take entire array from 0 to current index
  first[0] = 0;

  int longest = 0;
  int cur_mod = 0;
  for (int i = 0; i < n; i++) {
    cur_mod = (cur_mod + (ids[i] % 7)) % 7;

    if (first[cur_mod] != -1) {
      longest = max(longest, i-first[cur_mod]);
    } else {
      first[cur_mod] = i;
    }
  }

  cout << longest;
}