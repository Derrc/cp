#include <bits/stdc++.h>
using namespace std;

// topological sort + dp

constexpr int N = 1e5+5;
constexpr int M = 1e5+5;

vector<int> adj[N];
int indegree[N];
deque<int> q;
vector<int> topoSort;

// dp[i] = longest length of path that ends at node i
// rr:
// dp[i] = max(dp[i], dp[j] + 1) where j is the set of nodes j -> i
// dp[i] = 0 where i has indegree = 0
int dp[N]{};

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[--u].push_back(--v);
        indegree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push_back(i);
            topoSort.push_back(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();

        for (int nxt : adj[cur]) {
            if (--indegree[nxt] == 0) {
                topoSort.push_back(nxt);
                q.push_back(nxt);
            }
        }
    }

    int longest = 0;
    for (int u : topoSort) {
        for (int e : adj[u]) {
            dp[e] = max(dp[e], dp[u] + 1);
            longest = max(longest, dp[e]);
        }
    }

    cout << longest << endl;
}