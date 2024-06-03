#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
  Bitmask DP
*/

struct Cow {
  ll h, w, s;
};

int main() {
  freopen("guard.in", "r", stdin);
  freopen("guard.out", "w", stdout);

  int n, h;
  cin >> n >> h;

  vector<Cow> cows(n);
  for (int i = 0; i < n; i++) {
    cin >> cows[i].h >> cows[i].w >> cows[i].s;
  }

  // dp[i: {sf, height}] = max safety factor with subset i, current height of subset i
  vector<pair<ll, ll>> dp(1<<n);
  // base case: we want subests with one cow to always have its strength as sf
  dp[0] = {INT32_MAX, 0};
  ll best = -1;

  for (int s = 1; s < (1<<n); s++) {
    // we want sf to be -1 if its negative (not possible)
    dp[s] = {-1, 0};
    for (int i = 0; i < n; i++) {
      if (s & (1<<i)) {
        pair<ll, ll> prev = dp[s^(1<<i)];
        // calculate new sf
        ll new_sf = min(prev.first - cows[i].w, cows[i].s);

        dp[s].first = max(dp[s].first, new_sf);  
        dp[s].second = prev.second + cows[i].h;
      }
    }

    // update best sf if subset height is as tall
    if (dp[s].second >= h) {
      best = max(best, dp[s].first);
    }
  }

  if (best == -1) {
    cout << "Mark is too tall" << endl;
  } else {
    cout << best << endl;
  }
}