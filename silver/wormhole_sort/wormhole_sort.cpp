#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

/*
  Binary search / Connected components
  - since we are looking for minimum width that satisfies condition -> we can binary search it
  - sorted swap is possible if node i and its current position pi are in the same connected component -> check this condition
  - O((N+M)log 1e9)
*/

int n, m;
vector<int> position;
// adjacency list where pair is (end, width)
vector<vector<pair<int, int>>> adj;

// check if cows can be sorted with wormholes given a minimum width
bool can_swap(int width) {
  vector<int> components(n);
  vector<bool> visited(n);

  int component_num = 1;
  for (int c = 0; c < n; c++) {
    if (visited[c]) { continue; }

    // new component
    deque<int> q = {c};
    components[c] = component_num;
    visited[c] = true;

    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();

      for (pair<int, int> next : adj[cur]) {
        if (visited[next.first] || next.second < width) { continue; }

        components[next.first] = component_num;
        visited[next.first] = true;
        q.push_back(next.first);
      }
    }

    component_num++;
  }

  // for cows to be swapped, every node i and its position position[i] must be in the same component
  for (int i = 0; i < n; i++) {
    if (i == position[i]) { continue; }
    if (components[i] != components[position[i]]) {
      return false;
    }
  }

  return true;
}

int main() {
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);

  cin >> n >> m;

  position.resize(n);
  adj.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> position[i];
    // 0-index
    position[i]--;
  }

  for (int i = 0; i < m; i++) {
    int start, end, width;
    cin >> start >> end >> width;
    // 0-index
    start--;
    end--;

    adj[start].push_back({end, width});
    adj[end].push_back({start, width});
  }

  // binary search for maximum width
  int lo = 0;
  int hi = 1e9;
  while (lo < hi) {
    int width = lo + (hi - lo + 1) / 2;
    if (can_swap(width)) {
      lo = width;
    } else {
      hi = width-1;
    }
  }

  if (lo == 1e9) {
    cout << -1 << endl;
  } else {
    cout << lo << endl;
  }
}