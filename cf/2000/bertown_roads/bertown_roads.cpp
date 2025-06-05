#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

// Check for any bridges, if one exists we cannot orient edges in a direction to create a strongly connected graph
// Bridge detection using prefix sums
// dp[u] = # of edges that pass over edge pu, i.e. edges that connect an ancestor of pu to a descendent of pu (including u and p)
// dp[u] = (# of back edges up from u) + (dp[v] for all children v) - (# of forward edges down from u)

const int maxN = 1e5 + 5;

vector<int> adj[maxN];
int lvl[maxN];
int dp[maxN];
int bridgeCnt = 0;
vector<pii> spanEdges;
vector<pii> backEdges;

void dfs(int cur) {
  for (int nxt : adj[cur]) {
    // not visited nodes are part of spanning tree
    if (lvl[nxt] == 0) {
      lvl[nxt] = lvl[cur] + 1;
      dfs(nxt);
      dp[cur] += dp[nxt];
      spanEdges.push_back({cur, nxt});
    }
    // check for back edge that isn't parent
    else if (lvl[nxt] < lvl[cur] && lvl[nxt] + 1 < lvl[cur]) {
      dp[cur]++;
      backEdges.push_back({cur, nxt});
    }
    // check for forward edge
    else if (lvl[nxt] > lvl[cur]) {
      dp[cur]--;
    }
  }
  
  // accounts for subtracting parent-cur edge since we don't want to count that as a back edge
  // dp[cur]--;

  if (lvl[cur] > 1 && dp[cur] == 0) {
    bridgeCnt++;
  }
}


int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  lvl[0] = 1;
  dfs(0);

  if (bridgeCnt != 0) {
    cout << 0 << endl;
  } else {
    for (auto [u, v] : spanEdges) {
      cout << ++u << " " << ++v << "\n";
    }

    for (auto [u, v] : backEdges) {
      cout << ++u << " " << ++v << "\n";
    }
  }

  return 0;
}