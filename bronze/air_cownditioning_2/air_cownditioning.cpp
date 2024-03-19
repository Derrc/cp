#include <iostream>
#include <vector>
using namespace std;

/*
  brute force subsets:
  - test every combination (subset) of air conditioners and see if it satisfies cows
  - can use recursion to generate subsets
  using bitmasks:
  - each bit i in number will represent ac[i] being in possible subset
*/

int cow_n, ac_n;
vector<vector<int>> cows;
vector<vector<int>> ac;
vector<bool> uses;

int min_cost = INT32_MAX;

/*
  Returns the cost of the given ac subset if it is valid, otherwise returns -1
  For each cow, one or more acs must cool it down for the subset to be valid
*/
int get_cost(const vector<vector<int>> &subset) {
  int total = 0;
  // index i represents if ac is present and how much cooling is provided
  vector<vector<int>> ac_stalls(100, vector<int>(2));

  for (int ac = 0; ac < subset.size(); ac++) {
    int start = subset[ac][0];
    int end = subset[ac][1];
    int cools = subset[ac][2];
    int cost = subset[ac][3];

    // mark stalls as covered by ac and keeps track of total cooling provided
    for (int i = start; i <= end; i++) {
      ac_stalls[i][0] = 1;
      ac_stalls[i][1] += cools;
    }

    total += cost;
  }

  for (int c = 0; c < cow_n; c++) {
    int start = cows[c][0];
    int end = cows[c][1];
    int need = cows[c][2];
    
    for (int i = start; i <= end; i++) {
      if (!ac_stalls[i][0] || ac_stalls[i][1] < need) {
        return -1;
      }
    }
  }

  return total;
}

void search(int index) {
  if (index == ac_n) {
    // processing here
  } else {
    uses[index] = false;
    search(index+1);
    uses[index] = true;
    search(index+1);
  }
}

int main() {
  cin >> cow_n >> ac_n;

  cows.resize(cow_n, vector<int>(3));
  ac.resize(ac_n, vector<int>(4));
  uses.resize(ac_n);

  for (int i = 0; i < cow_n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> cows[i][j];
    }
  }

  for (int i = 0; i < ac_n; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> ac[i][j];
    }
  }

  // bitmask from 0 to 2^(9)-1 (10 bits)
  for (int mask = 0; mask < (1 << ac_n); mask++) {
    vector<vector<int>> subset;
    for (int b = 0; b < ac_n; b++) {
      // check if bth bit is active
      if (mask & (1 << b)) { subset.push_back(ac[b]); }
    }

    int cost = get_cost(subset);

    if (cost != -1) {
      min_cost = min(min_cost, cost);
    }
  }

  cout << min_cost;
}