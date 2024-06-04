#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  int moves = 0;
  while (n != m) {
    if (m < n) {
      moves += n-m;
      break;
    }
    if (m % 2 == 0) {
      m /= 2;
      moves++;
    } else {
      m = (m+1)/2;
      moves += 2;
    }
  }

  cout << moves << endl;
}