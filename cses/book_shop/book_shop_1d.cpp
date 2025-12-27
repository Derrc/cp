#include <iostream>
#include <vector>
using namespace std;

int constexpr N = 1005;
int constexpr X = 1e5+5;

int v[N];
int w[N];
// dp[i] = max value subset that can be constructed with all items with a weight sum <= i
int dp[X];

int main() {
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }


    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j >= w[i]) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[x] << endl;
}