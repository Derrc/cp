#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
  Successor (Functional) Graphs:
  - directed graph where each node has one starting edge, i.e. each node has one successor
  - 1 cycle exists since there are n nodes and n edges
  - detect cycle with Floyd's Algorithm
*/

vector<int> move(const vector<int> &to_move) {
  // move pieces
  cout << "next" << " ";
  for (int i = 0; i < to_move.size()-1; i++) {
    cout << to_move[i] << " ";
  }
  cout << to_move.back() << endl;

  // return location of pieces
  vector<int> groups(10);
  int group_num;
  cin >> group_num;
  for (int g = 0; g < group_num; g++) {
    string next;
    cin >> next;
    for (char i : next) {
      groups[i - '0'] = g;
    }
  }
  
  return groups;
}

int main() {
  // simulate first step
  move({0, 1});
  vector<int> groups = move({1});
  // start Floyd's algorithm
  while (groups[0] != groups[1]) {
    move({0, 1});
    groups = move({1});
  }

  // move everyone until they meet (start of cycle)
  while (groups[1] != groups[2]) {
    groups = move({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  }

  cout << "done" << endl;
}