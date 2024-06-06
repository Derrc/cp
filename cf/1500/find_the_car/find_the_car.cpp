#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int bs(vector<ll> &arr, int target, int lo, int hi) {
  while (lo <= hi) {
    int mid = lo + (hi-lo)/2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }
  // naturally returns lower bound
  return lo;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k, q;
    cin >> n >> k >> q;

    vector<ll> dist(k+1);
    vector<ll> time(k+1);
    for (int i = 1; i <= k; i++) { cin >> dist[i]; }
    for (int i = 1; i <= k; i++) { cin >> time[i]; }

    for (int i = 0; i < q; i++) {
      int d;
      cin >> d;

      int lb = bs(dist, d, 0, k+1);
      if (dist[lb] == d) {
        cout << time[lb] << "\n";
        continue;
      }

      ll ans = time[lb-1] + (d-dist[lb-1])*(time[lb]-time[lb-1])/(dist[lb]-dist[lb-1]);
      cout << ans << "\n";
    }
  }
}