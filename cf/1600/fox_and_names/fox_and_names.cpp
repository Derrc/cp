#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[26];
bool vis[26];
bool path[26];
bool cycle = false;
vector<int> topSort;


void dfs(int cur) {
  vis[cur] = true;
  path[cur] = true;
  for (int nxt : adj[cur]) {
    if (path[nxt]) {
      cycle = true;
      break;
    }
    else if (!vis[nxt]) {
      dfs(nxt);
    }
  }

  path[cur] = false;
  topSort.push_back(cur);
}

int main() {
  int n;
  cin >> n;

  vector<string> words(n);
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }

  
  for (int i = 0; i < n-1; i++) {
    string w1 = words[i], w2 = words[i+1];
    int j = 0;
    while (w1[j] == w2[j]) {
      j++;
    }

    // if w2 is a substring of w2, then impossible
    if (j == w2.size()) {
      cout << "Impossible" << endl;
      return 0;
    }
    // if w1 is a substring of w2, then no edge to add
    else if (j == w1.size()) {
      continue;
    }
    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
  }

  for (int i = 0; i < 26; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  if (cycle) {
    cout << "Impossible";
  } else {
    reverse(topSort.begin(), topSort.end());
    for (int i : topSort) {
      cout << (char)('a' + i);
    }
  }

  cout << endl;

  return 0;
}

