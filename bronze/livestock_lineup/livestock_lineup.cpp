#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
  brute force permutations: get all permutations of cows and check if each satisfies the constraints
  - create permutations in alphabetical order by sorting cow names first
*/

int constraints_n;
vector<vector<string>> constraints;
vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<vector<string>> orderings;
vector<bool> visited(8);

/*
  Returns index of given cow in vec
*/
int loc(const vector<string> &order, const string &cow) {
  for (int i = 0; i < order.size(); i++) {
    if (order[i] == cow) {
      return i;
    }
  }

  return -1;
}

/*
  Checks if given permutation ordering is valid with constraints
  - since to be valid cows must be next to each other, check if difference between indexes of cows is 1
*/
bool check(const vector<string> &order) {
  for (int c = 0; c < constraints_n; c++) {
    string cow1 = constraints[c][0];
    string cow2 = constraints[c][5];

    if (abs(loc(order, cow1) - loc(order, cow2)) != 1) {
      return false;
    }
  }

  return true;
}

/*
  Recurses to create permutations
*/
void search(vector<string> cur) {
  if (cur.size() == cows.size()) {
    orderings.push_back(cur);
    return;
  }

  for (int i = 0; i < cows.size(); i++) {
    if (visited[i]) { continue; }

    visited[i] = true;
    cur.push_back(cows[i]);
    search(cur);
    visited[i] = false;
    cur.pop_back();
  }
}

int main() {
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);

  cin >> constraints_n;

  constraints.resize(constraints_n, vector<string>(6));

  for (int i = 0; i < constraints_n; i++) {
    for (int w = 0; w < 6; w++) {
      cin >> constraints[i][w];
    }
  }

  sort(cows.begin(), cows.end());

  search({});

  for (vector<string> &ordering : orderings) {
    if (check(ordering)) {
      for (int i = 0; i < ordering.size(); i++) {
        cout << ordering[i] << "\n";
      }
      break;
    }
  }
}