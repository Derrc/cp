#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

// All trees are bipartite (no cycles of odd length)
// Maximum moves is 3n meaning we have max 3 moves to reduce the size of the tree by 1 node
// Goal: destroy all leaf nodes whilst moving in-between nodes until only remaining node is n
// We can do this by rooting the tree arbitrarily and running a DFS to partition nodes into odd-depth and even-depth
// To destroy a leaf node v with depth i while standing on a node with depth j:
// - if depth parity of i == j -> move 1 node before destroying (guarantees that we don't destroy a node we're standing on)
// - if depth parity of i != j -> move 2 nodes before destroying (guarantees that we move at least once before applying a destroy operation)


vector<vector<int>> adj;
vector<int> depth, parent, children;

void dfs(int cur, int prev) {
    if (prev != -1) {
        depth[cur] = depth[prev] + 1;
    }
    parent[cur] = prev;

    for (int nxt : adj[cur]) {
        if (nxt == prev) { continue; }

        dfs(nxt, cur);
        children[cur]++;
    }
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n, vector<int>());
    depth.assign(n, 0);
    parent.assign(n, -1);
    children.assign(n, 0);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;

        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    // root at end node n so that it is the only one remaining as we destroy leaf nodes
    dfs(n-1, -1);

    vector<vector<int>> leaves(2);
    for (int i = 0; i < n-1; i++) {
        if (children[i] == 0) {
            leaves[depth[i] & 1].push_back(i);
        }
    }

    vector<pii> ans;
    int cur = depth[0] & 1;
    // destroy all nodes but root
    for (int i = 0; i < n-1; i++) {
        // check if opposite parity doesn't have any leaves -> we have to move first to avoid destroying the node we're standing on
        if (leaves[cur ^ 1].empty()) {
            ans.push_back({1, -1});
            cur ^= 1;
        }

        int destroy = leaves[cur ^ 1].back();
        leaves[cur ^ 1].pop_back();
        ans.push_back({2, destroy});

        // add new leaf node created by destroying
        int p = parent[destroy];
        if (--children[p] == 0) {
            leaves[depth[p] & 1].push_back(p);
        }

        ans.push_back({1, -1});
        cur ^= 1;
    }

    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        if (x == 1) {
            cout << 1 << "\n";
        } else {
            cout << "2 " << y+1 << "\n";
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    cout << endl;
}