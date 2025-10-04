#include <bits/stdc++.h>
using namespace std;

constexpr int N = 305;

int n;
// dp[i][j][k] = expected number of rolls to finish i 1-sushi plates, j 2-sushi plates, and k 3-sushi plates
// rr: (Law of total expectation)
// dp[i][j][k] = 1 +
// P(i) * dp[i-1][j][k] +
// P(j) * dp[i+1][j-1][k] +
// P(k) * dp[i][j+1][k-1] +
// P(n-i-j-k) * dp[i][j][k]
// dp[0][0[][0] = 0
double dp[N][N][N];
int p[4];

double f(int s1, int s2, int s3) {
    if (s1 == 0 && s2 == 0 && s3 == 0) {
        return 0;
    }
    if (dp[s1][s2][s3] != -1) {
        return dp[s1][s2][s3];
    }

    double res = 1;
    if (s1 > 0) {
        res += ((double)s1 / n) * f(s1-1, s2, s3);
    }
    if (s2 > 0) {
        res += ((double)s2 / n) * f(s1+1, s2-1, s3);
    }
    if (s3 > 0) {
        res += ((double)s3 / n) * f(s1, s2+1, s3-1);
    }

    res *= (double)n / (s1+s2+s3);
    return dp[s1][s2][s3] = res;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        p[x]++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    cout << setprecision(10) << f(p[1], p[2], p[3]) << endl;
}