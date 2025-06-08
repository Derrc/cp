#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Just need to check if n is a perfect square

bool isPerfectSquare(int n) {
  int root = round(sqrt(n));
  return (root * root) == n;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if (isPerfectSquare(n)) {
      cout << sqrt(n) << " " << 0 << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  
  return 0;
}