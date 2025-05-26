#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

// BFS from 0 to find all minimum distances from numbers 0 - 32768
// Inverse edge for multiply is either a / 2 or (32768 + a) / 2

const int mod = 32768;
int a[32770]{};
int dist[32770];

void bfs() {
  memset(dist, -1, sizeof(dist));
  dist[0] = 0;
  
  deque<int> q;
  q.push_back(0);
  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();

    int first = (cur + mod - 1) % mod;
    if (dist[first] == -1) {
      dist[first] = dist[cur] + 1;
      q.push_back(first);
    }

    if (cur % 2 == 0) {
      int second = cur / 2;
      if (dist[second] == -1) {
        dist[second] = dist[cur] + 1;
        q.push_back(second);
      }
      second += mod / 2;
      if (dist[second] == -1) {
        dist[second] = dist[cur] + 1;
        q.push_back(second);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  bfs();

  for (int i = 0; i < n; i++) {
    cout << dist[a[i]] << " ";
  }
  cout << endl;

  return 0;
}