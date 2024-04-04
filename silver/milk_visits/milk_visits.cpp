#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
  Tree traversal DFS
  - brute force -> O(N*M): traverse entire tree for every friend query to see if path is happy or not
  - O(N+M): get connected components for each breed
  - if start and end are in the same connected component, must either be 1 or 0 depending on friend's pref
  - if start and end are in different components (even if breed is the same in both components), always 1 because the path contains nodes with both breeds
*/

// farm i has type milk[i]
vector<char> milk;
vector<vector<int>> adj;
// farm i is in component components[i], also acts as visited array
vector<int> components;

void bfs(int node, int component_num) {
  deque<int> q = {node};
  components[node] = component_num;

  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    for (int child : adj[cur]) {
      if (components[child] || milk[child] != milk[node]) { continue; }

      q.push_back(child);
      components[child] = component_num;
    }
  }
}

int main() {
  freopen("milkvisits.in", "r", stdin);
  freopen("milkvisits.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  milk.resize(n);
  adj.resize(n);
  components.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> milk[i];
  }

  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    adj[--a].push_back(--b);
    adj[b].push_back(a);
  }

  // get connected components by breed
  int component_num = 1;
  for (int i = 0; i < n; i++) {
    if (components[i]) { continue; }

    bfs(i, component_num);
    component_num++;
  }

  // process each query
  for (int i = 0; i < m; i++) {
    int start, end;
    char pref;
    cin >> start >> end >> pref;
    start--;
    end--;

    if (components[start] == components[end]) {
      cout << (milk[start] == pref);
    }
    else {
      cout << 1;
    }
  }
}