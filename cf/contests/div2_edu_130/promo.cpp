#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5 + 5;
int p[N]{};
ll pSum[N]{};

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p + n);

    for (int i = 0; i < n; i++) {
        pSum[i+1] = pSum[i] + p[i];
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        cout << pSum[n-x+y] - pSum[n-x] << "\n";
    }
}