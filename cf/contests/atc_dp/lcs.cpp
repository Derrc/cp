#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3005;

// dp[i][j] = length of LCS using first i characters of s and first j characters of t
// rr:
// s[i] == t[j] -> dp[i][j] = 1 + dp[i-1][j-1]
// s[i] != t[j] -> dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// dp[i][0] = dp[0][j] = 0
int dp[N][N]{};

int main() {
    string s, t;
    cin >> s >> t;

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= t.length(); j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // reconstruct solution using grid starting at dp[s.length()][t.length()]
    // diagonal jumps that are connected to dp[s.length()][t.length()] are part of the solution
    // s[i] == t[j] -> s[i] is part of the solution -> travel diagonally
    // dp[i-1][j] > dp[i][j-1] -> travel up
    // do[i][j-1] > dp[i-1][j] -> travel left
    string ans;
    int i = s.length(), j = t.length();
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            ans.push_back(s[i-1]);
            i--;
            j--;
        } else {
            dp[i-1][j] > dp[i][j-1] ? i-- : j--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}
