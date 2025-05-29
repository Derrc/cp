#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// Sort adjacency list nodes in order of BFS sequence
// Compare using node positions array

vector<int> adj[200005];
int seq[200005];
int pos[200005];
bool vis[200005];
vector<int> res;

bool cmp(int a, int b) {
  return pos[a] < pos[b];
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }
  
  for (int i = 0; i < n; i++) {
    cin >> seq[i];
    seq[i]--;
    pos[seq[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    sort(adj[i].begin(), adj[i].end(), cmp);
  }

  deque<int> q;
  q.push_back(0);
  vis[0] = true;
  while(!q.empty()) {
    int cur = q.front();
    q.pop_front();

    res.push_back(cur);
    for (int next : adj[cur]) {
      if (!vis[next]) {
        q.push_back(next);
        vis[next] = true;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (seq[i] != res[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}