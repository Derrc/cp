#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

/*
  Greedy / Prefix/Suffix Sum

  Problem: make array palindromic with minimum operations (1 op = adding k to any index)
  - split into modulo k groups
  - even case: pair consecutive numbers in sorted order
  - odd case: try all possible i as unpaired number, pair rest like even case, optimal to try odd indices of i
*/

const ll INF = 1e18;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    map<int, vector<int>> groups;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      groups[a % k].push_back(a);
    }

    ll res = 0;
    bool odd = false;
    for (auto [i, g] : groups) {
      sort(g.begin(), g.end());

      if (g.size() % 2 == 0) {
        // even case
        for (int j = 0; j < g.size(); j += 2) {
          res += (g[j+1] - g[j]) / k;
        }
      } else {
        // odd case
        if (odd) {
          res = -1;
          break;
        }
        vector<ll> pref(g.size()+1); // before i
        vector<ll> suff(g.size()+1); // after i

        for (int j = 2; j < g.size(); j += 2) {
          pref[j] = pref[j-2] + (g[j-1] - g[j-2]) / k;
        }

        for (int j = g.size() - 3; j >= 0; j -= 2) {
          suff[j] = suff[j+2] + (g[j+2] - g[j+1]) / k;
        }

        ll best = INF;
        for (int i = 0; i < g.size(); i += 2) {
          best = min(best, pref[i] + suff[i]);
        }

        res += best;
        odd = true;
      }
    }

    cout << res << "\n";
  }

}