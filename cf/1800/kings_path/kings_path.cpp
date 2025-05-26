#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
using namespace std;
using pii = pair<int, int>;

// BFS from start to end
// Can store allowed / visited in memory since total sum of allowed segments is <= 10^5

int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};

int main() {
  pii start, end;
  cin >> start.first >> start.second >> end.first >> end.second;

  int n;
  cin >> n;

  set<pii> allowed;
  for (int i = 0; i < n; i++) {
    int r, a, b;
    cin >> r >> a >> b;
    for (int c = a; c <= b; c++) {
      allowed.insert({r, c});
    }
  }

  deque<pii> q;
  set<pii> visited;
  q.push_back(start);
  visited.insert(start);
  
  int level = 0;
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      auto [r, c] = q.front();
      q.pop_front();

      if (r == end.first && c == end.second) {
        cout << level << endl;
        exit(0);
      }

      for (int i = 0; i < 8; i++) {
        int nr = r + dy[i];
        int nc = c + dx[i];

        if (visited.count({nr, nc}) == 0 && allowed.count({nr, nc}) == 1) {
          q.push_back({nr, nc});
          visited.insert({nr, nc});
        }
      }
    }
    level++;
  }

  cout << -1 << endl;
}