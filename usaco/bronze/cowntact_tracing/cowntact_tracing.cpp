#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// brute force:
// simulate problem and check all values of K and see if it is consistent with data
// K can range from 0 to T

int main() {
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);

  int cows_n, t;
  string s;

  cin >> cows_n >> t >> s;

  vector<bool> end_infected(cows_n);

  // mark end infected cows
  for (int i = 0; i < cows_n; i++) {
    end_infected[i] = s[i] == '1' ? true : false;
  }

  vector<vector<int>> shakes(t, vector<int>(3));

  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> shakes[i][j];
      // subtract 1 to account for zero-indexing
      shakes[i][j]--;
    }
  }

  // sort shakes by time
  sort(shakes.begin(), shakes.end());

  int min_k = t;
  int max_k = -1;
  unordered_set<int> patient_zeros;
  vector<bool> infected(cows_n);
  vector<int> shakes_count(cows_n);

  // test each possible value of k and patient zero candidate
  for (int k = 0; k <= t; k++) {
    for (int pz = 0; pz < cows_n; pz++) {
      infected[pz] = true;
      for (int i = 0; i < t; i++) {
        int cow1 = shakes[i][1];
        int cow2 = shakes[i][2];
        // get infected state before we update to prevent accessing updated state
        bool cow1_infected = infected[cow1];
        bool cow2_infected = infected[cow2];

        // simulate shake
        if (cow1_infected && shakes_count[cow1] < k) {
          shakes_count[cow1]++;
          infected[cow2] = true;
        }
        if (cow2_infected && shakes_count[cow2] < k) {
          shakes_count[cow2]++;
          infected[cow1] = true;
        }
      }

      // check that end state and infected vector are equal
      bool equal = true;
      for (int c = 0; c < cows_n; c++) {
        if (infected[c] != end_infected[c]) {
          equal = false;
          break;
        }
      }

      if (equal) {
        patient_zeros.insert(pz);
        min_k = min(min_k, k);
        max_k = max(max_k, k);
      }

      // reset vector values
      infected.assign(infected.size(), false);
      shakes_count.assign(shakes_count.size(), 0);
    }
  }

  cout << patient_zeros.size() << " " << min_k << " " << (max_k == t ? "Infinity" : to_string(max_k));
}
