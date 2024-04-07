#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
  Bitwise operations
  - addition and xor using only & and |
*/

int ask(int i1, int i2, string op) {
  cout << op << " " << i1 << " " << i2 << endl;
  int ans;
  cin >> ans;
  return ans;
}

int sum(int i1, int i2) {
  // 0-index
  int and_ = ask(++i1, ++i2, "and");
  int or_ = ask(i1, i2, "or");

  // xor
  int xor_ = ~and_ & or_;
  
  // sum
  return (and_ << 1) + xor_;
}

int main() {
  int n, k;
  cin >> n >> k;

  int a_plus_b = sum(0, 1);
  int b_plus_c = sum(1, 2);
  int a_plus_c = sum(0, 2);

  vector<int> arr;
  // get a
  arr.push_back((a_plus_b + a_plus_c - b_plus_c) / 2);
  // get b
  arr.push_back(a_plus_b - arr.back());
  // get c
  arr.push_back(b_plus_c - arr.back());

  // get rest of array
  for (int i = 3; i < n; i++) {
    arr.push_back(sum(i, i-1) - arr.back());
  }

  sort(arr.begin(), arr.end());

  cout << "finish" << " " << arr[k-1] << endl;
}