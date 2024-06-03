#include <iostream>
#include <array>
#include <vector>
#include <set>
using namespace std;

// brute force:
// for each pair of cows: we can check if cow1 is consistently better than cow2, if it is add to our result
// we can check this by comparing the indexes of both cows in a session: if the index of cow1 is less than cow2, it was better

int indexOf(const vector<int> &vec, const int &target ) {
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == target) {
      return i;
    }
  }

  return -1;
}

int main() {
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int sessions_n, cows_n;
  cin >> sessions_n >> cows_n;

  vector<vector<int>> sessions(sessions_n, vector<int>(cows_n));

  for (int s = 0; s < sessions_n; s++) {
    vector<int> line;
    for (int c = 0; c < cows_n; c++) {
      cin >> sessions[s][c];
    }
  }

  int pairs = 0;
  for (int c1 = 1; c1 <= cows_n; c1++) {
    for (int c2 = 1; c2 <= cows_n; c2++) {
      if (c1 == c2) { continue; }

      bool better = true;
      for (const vector<int> &session : sessions) {
        if (indexOf(session, c1) > indexOf(session, c2)) {
          better = false;
          break;
        }
      }

      pairs += better;
    }
  }

  cout << pairs;
}