#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Assign parity to each node
// BFS from a node and partition nodes into sets with even and odd distances (similar to 2-coloring)
// Answer will be the set with size <= floor(n/2)
// An even node is guarenteed to be connected to an odd node by an edge and vice-versa 

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[--u].push_back(--v);
      adj[v].push_back(u);
    }

    deque<int> q;
    vector<int> dist(n, -1);
    vector<bool> odd(n);
    int oddNum = 0;
    q.push_back(0);
    dist[0] = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();

      for (int next : adj[cur]) {
        if (dist[next] == -1) {
          dist[next] = 1 + dist[cur];
          q.push_back(next);
          if (dist[next] & 1) {
            odd[next] = true;
            oddNum++;
          }
        }
      }
    }

    bool chooseOdd = oddNum <= (n / 2);
    cout << (chooseOdd ? oddNum : n - oddNum) << "\n";
    for (int i = 0; i < n; i++) {
      if ((chooseOdd && odd[i]) || (!chooseOdd && !odd[i])) {
        cout << i+1 << " ";
      }
    }
    cout << "\n";
  }
}