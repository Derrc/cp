#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int constexpr N = 2e5+5;
// Sieve of Eratosthenes O(NlogN)
vector<vector<int>> prime(N+1);

int solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        for (int x : prime[a[i]]) {
            if (cnt[x] > 0) {
                return 0;
            }
            cnt[x]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int x : prime[a[i]]) {
            cnt[x]--;
        }

        for (int x : prime[a[i]+1]) {
            if (cnt[x] > 0) {
                return 1;
            }
        }

        for (int x : prime[a[i]]) {
            cnt[x]++;
        }
    }

    return 2;
}

int main() {
    int t;
    cin >> t;

    for (int i = 2; i < N; i++) {
        if (!prime[i].empty()) {
            continue;
        }

        for (int j = i; j < N; j+=i) {
            prime[j].push_back(i);
        }
    }

    while (t--) {
        cout << solve() << "\n";
    }

    cout << endl;
}