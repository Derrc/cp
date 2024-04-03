#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> position;
vector<int> wormhole;
// adjacency list where pair is (end, width)
vector<vector<pair<int, int>>> adj;

struct Wormhole {
  int a, b, w;
};

int main() {
  int n, m;
  cin >> n;

  position.resize(n);
  wormhole.resize(m);
  adj.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> position[i];
    // 0-index
    position[i]--;
  }

  for (int i = 0; i < m; i++) {
    Wormhole wh;
    cin >> wh.a >> wh.b >> wh.w;
    // 0-index
    wh.a--;
    wh.b--;
    wormhole[i] = wh;
  }

  for (int i = 0; i < m; i++) {
    Wormhole wh = wormhole[i];
    adj[wh.a].push_back(make_pair(wh.b, wh.w));
    adj[wh.b].push_back(make_pair(wh.a, wh.w));
  }


}