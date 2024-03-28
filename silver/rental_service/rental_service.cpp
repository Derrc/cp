#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool cmp(int a, int b) {
  return a > b;
}

bool ycmp(pair<int, int> &p1, pair<int, int> &p2) {
  return p1.second > p2.second;
}

int main() {
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);

  int n, m, r;
  cin >> n >> m >> r;

  vector<int> milk(n);
  vector<pair<int, int>> buy(m);
  vector<int> rent(r);

  for (int i = 0; i < n; i++) {
    cin >> milk[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> buy[i].first >> buy[i].second;
  }

  for (int i = 0; i < r; i++) {
    cin >> rent[i];
  }

  sort(milk.begin(), milk.end(), cmp);
  sort(buy.begin(), buy.end(), ycmp);
  sort(rent.begin(), rent.end(), cmp);

  vector<ll> profit_milk(n+1);
  vector<ll> profit_rent(r+1);

  int cur = 0;
  for (int i = 1; i <= n; i++) {
    ll profit = 0;
    int gallons = milk[i-1];

    while (cur < m && gallons > 0) {
      if (gallons >= buy[cur].first) {
        profit += buy[cur].second * buy[cur].first;
        gallons -= buy[cur].first;
        buy[cur].first = 0;
        cur++;
      }
      else {
        profit += buy[cur].second * gallons;
        buy[cur].first -= gallons;
        gallons = 0;
      }
    }

    profit_milk[i] = profit_milk[i-1] + profit;
  }

  for (int i = 1; i <= r; i++) {
    profit_rent[i] = rent[i-1] + profit_rent[i-1];
  }

  ll max_profit = 0;
  for (int i = 1; i <= n; i++) {
    if (n-i > r) {
      max_profit = max(max_profit, profit_milk[i]);
    }
    else {
      max_profit = max(max_profit, profit_milk[i] + profit_rent[n-i]);
    }
  }

  cout << max_profit;
}