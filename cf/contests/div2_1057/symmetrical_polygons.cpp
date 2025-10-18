#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<int> s;
    ll p = 0;
    int sides = 0;
    for (auto &[k, v] : cnt) {
        int rounded = v / 2 * 2;
        sides += rounded;
        p += 1LL * k * rounded;
        if (v % 2 != 0) {
            s.push_back(k);
        }
    }

    // no pairs -> cannot create symmetrical polygon
    if (p == 0) {
        return 0;
    }

    sort(s.begin(), s.end(), [](const int s1, const int s2) {
        return s1 > s2;
    });

    // find first set of singles where absdiff(s1, s2) < P(pairs)
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] - s[i] < p) {
            return p + s[i-1] + s[i];
        }
    }

    // else find if we can use any singles
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < p) {
            return p + s[i];
        }
    }

    // else only pairs -> must be at least 3 sides to create polygon
    return sides < 3 ? 0 : p;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }

    cout << endl;
}

