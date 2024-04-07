#include <vector>
#include <iostream>
#include <string>
using namespace std;

/*
  Bitmasks
  - problem can be reformulated as finding min edit distance from the inverse of team t to any other team
  - have a edit-distance arr where arr[i] represents the min edits to get to i (bitmasked) from any team
  - will eventually store all possible edit permutations 2^C
*/

int main() {
  int c, n;
  cin >> c >> n;

  vector<int> teams(n);
  vector<int> dists(1 << c, INT32_MAX);

  for (int i = 0; i < n; i++) {
    string team;
    cin >> team;

    // create bitmask (1 = G, 0 = H)
    int mask = 0;
    for (int ch = 0; ch < c; ch++) {
      if (team[ch] == 'G') {
        mask += (1 << (c - 1 - ch));
      }
    }

    teams[i] = mask;
    // edit distance of teams are 0
    dists[mask] = 0;
  }

  for (int i = 0; i < c; i++) {
    for (int mask = 0; mask < (1 << c); mask++) {
      if (dists[mask] == INT32_MAX) { continue; }

      // flip the ith bit
      dists[mask ^ (1 << i)] = min(dists[mask ^ (1 << i)], dists[mask] + 1);
    }
  }

  for (int i = 0; i < n; i++) {
    // get min distance of inverse of each team (c - min = max distance)
    cout << c - dists[teams[i] ^ ((1 << c) - 1)] << '\n';
  }
}