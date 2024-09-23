#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

/*
  Top-down DP
  - dp[(i, num programmers, num testers)] = skill from ith candidate with given # of p and t to fulfill
  - keep track of current skill as we check each index
*/

struct State {
  int i, np, nt;
  bool operator<(const State& s) const {
    if (i == s.i && np == s.np) {
      return nt < s.nt;
    } else if (i == s.i) {
      return np < s.np;
    }
    return i < s.i;
  }
};

int n, m;
vector<ll> a;
vector<ll> b;
map<State, ll> dp;

// return true if assign i to p and false if need to assign i to t
bool check(int i, int np, int nt) {
  if (np == 0) { return false; }
  if (nt == 0) { return true; }
  return a[i] > b[i];
}

ll dfs(int i, int np, int nt) {
  if (i == n+m+1) {
    return 0;
  }
  State s = {i, np, nt};
  if (dp.count(s)) {
    return dp[s];
  }

  if (check(i, np, nt)) {
    dp[s] = a[i] + dfs(i+1, np-1, nt);
  } else {
    dp[s] = b[i] + dfs(i+1, np, nt-1);
  }

  return dp[s];
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    a.resize(n+m+1);
    b.resize(n+m+1);
    dp.clear();
    for (int i = 0; i < n+m+1; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n+m+1; i++) {
      cin >> b[i];
    }

    ll s = 0;
    int np = n, nt = m;
    for (int i = 0; i < n+m+1; i++) {
      cout << (s + dfs(i+1, np, nt)) << " ";
      if (check(i, np, nt)) {
        s += a[i];
        np--;
      } else {
        s += b[i];
        nt--;
      }
    }

    cout << "\n";
  }
}