#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3005;

double p[N]{};
// dp[i][j] = probability of flipping j heads from the first i coins
// rr:
// Either ith coin is heads or tails (Law of total probability)
// dp[i][j] = dp[i-1][j-1] * P(H, i) + dp[i-1][j] * P(T, i)
// dp[0][0] = 1 (probability of getting 0 heads with 0 coins is 1)
double dp[N][N]{};

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i-1][j] * (1 - p[i]);
            if (j > 0) {
                dp[i][j] += dp[i-1][j-1] * p[i];
            }
        }
    }

    // P(more heads than tails)
    // Sum of answers for dp[n][[n//2+1, n]]
    double res = 0;
    for (int j = n/2+1; j <= n; j++) {
        res += dp[n][j];
    }

    cout << setprecision(10) << res << endl;
}