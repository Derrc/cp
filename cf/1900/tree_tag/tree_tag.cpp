#include <iostream>
#include <vector>
using namespace std;

// Case analysis
// 1: dist(a, b) <= da -> Alice can win in 1st move
// 2: 2da >= diameter -> Alice can jump to anywhere from the middle node
// 3: db > 2da -> Whenever Alice is within da of Bob, Bob can jump 2da + 1 nodes away
// 4: db <= 2da -> Whenever Alice is within da of Bob, Bob can jump max 2da nodes away, where Alice is then da within Bob and wins in the next move

int const maxN = 1e5 + 5;

vector<int> adj[maxN];
int dist[maxN];

int dfs(int cur, int prev, int d) {
  dist[cur] = d;
  int maxDepthNode = cur;
  for (int nxt : adj[cur]) {
    if (nxt != prev) {
      int x = dfs(nxt, cur, d + 1);
      if (dist[x] > dist[maxDepthNode]) {
        maxDepthNode = x;
      }
    }
  }
  return maxDepthNode;
}

void solve() {
  fill(begin(adj), end(adj), vector<int>());

  int n, a, b, da, db;
  cin >> n >> a >> b >> da >> db;
  a--;
  b--;

  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;

    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  int startN = dfs(a, -1, 0);
  if (dist[b] <= da) {
    cout << "Alice" << "\n";
    return;
  }

  int endN = dfs(startN, -1, 0);

  int diameter = dist[endN];

  if ((2*da >= diameter) || db <= 2*da) {
    cout << "Alice" << "\n";
  } else {
    cout << "Bob" << "\n";
  }

  return;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}