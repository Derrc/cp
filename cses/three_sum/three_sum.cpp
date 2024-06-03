#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
  int n, target;

  cin >> n >> target;

  // store value along with previous index before sorting
  vector<pair<ll, ll>> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++) {
    int l = 0;
    int r = n-1;
    while (l < r) {
      if (l == i) {
        l++;
        continue;
      }
      if (r == i) {
        r--;
        continue;
      }

      ll sum = arr[i].first + arr[l].first + arr[r].first;
      if (sum == target) {
        cout << arr[i].second+1 << " " << arr[l].second+1 << " " << arr[r].second+1;
        exit(0);
      }
      else if (sum > target) {
        r--;
      }
      else if (sum < target) {
        l++;
      }

    }
  }

  cout << "IMPOSSIBLE";
}