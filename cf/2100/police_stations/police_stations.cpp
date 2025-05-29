#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;
using pii = pair<int, int>;

// BFS from every police station and remove the road when we reach a visited node (that is not in current path)
// Since every city is reachable by a police station at the start
// Meeting roads are guarenteed to be reachable by a police station

const int maxN = 300005;

vector<pii> adj[maxN];
bool p[maxN];
bool vis[maxN];

int main() {
  int n, k, d;
  cin >> n >> k >> d;

  for (int i = 0; i < k; i++) {
    int s;
    cin >> s;
    p[--s] = true;
  }

  deque<pii> q;
  for (int i = 0; i < n; i++) {
    if (p[i]) {
      q.push_back({i, -1});
      vis[i] = true;
    }
  }

  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back({--v, i});
    adj[v].push_back({u, i});
  }

  set<int> res;
  while (!q.empty()) {
    auto [cur, prev] = q.front();
    q.pop_front();

    for (auto [next, i] : adj[cur]) {
      if (next != prev) {
        if (vis[next]) {
          res.insert(i);
        } else {
          q.push_back({next, cur});
          vis[next] = true;
        }
      }
    }
  }

  cout << res.size() << "\n";
  for (int e : res) {
    cout << ++e << " ";
  }

  return 0;
}