#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  2-Pointers with maximum suffix array
  - 2P to get max diamonds starting with each diamond (1st set)
  - maximum suffix array to get max diamonds after a certain index (2nd set)
*/

int main() {
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);
  
  int n, k;

  cin >> n >> k;

  vector<int> diamonds(n);

  for (int i = 0; i < n; i++) {
    cin >> diamonds[i];
  }

  sort(diamonds.begin(), diamonds.end());

  // maxLeft[i] = max diamonds where start is at i
  vector<int> maxLeft(n);

  int r = 0;
  for (int l = 0; l < n; l++) {
    while (r < n && diamonds[r] - diamonds[l] <= k) {
      r++;
    }
    maxLeft[l] = r-l;
  }

  // maxRight[i] = max diamonds where start is any x >= i
  // max suffix array
  vector<int> maxRight(n+1);
  maxRight[n] = 0;
  
  for (int i = n-1; i >= 0; i--) {
    // max will either be previously seen max or new max that starts at i
    maxRight[i] = max(maxRight[i+1], maxLeft[i]);
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    count = max(count, maxLeft[i] + maxRight[i + maxLeft[i]]);
  }

  cout << count;
}