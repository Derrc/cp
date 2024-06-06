#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
  return p1.first > p2.first;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }

    vector<int> q(n);
    vector<pair<int, int>> v;
    int n_i = find(p.begin(), p.end(), n) - p.begin();
    // n is in even pos
    if (n_i % 2 == 0) {
      for (int i = 1; i < n; i += 2) {
        v.push_back({p[i], i});
      }
      for (int i = 0; i < n; i += 2) {
        v.push_back({p[i], i});
      }
    }
    // n is in odd pos
    else {
      for (int i = 0; i < n; i += 2) {
        v.push_back({p[i], i});
      }
      for (int i = 1; i < n; i += 2) {
        v.push_back({p[i], i});
      }
    }

    sort(v.begin(), v.begin() + n/2, cmp);
    sort(v.begin() + n/2, v.end(), cmp);
    // give 1-(n/2) to non-maxima positions in descending order
    // give (n/2)+1-n to maxima positions in descending order
    for (int i = 0; i < n; i++) {
      q[v[i].second] = i+1;
    }

    for (int i = 0; i < n; i++) {
      cout << q[i] << " ";
    }
    cout << "\n";
  }
}