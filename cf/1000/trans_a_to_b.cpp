#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  // try to go from b to a
  vector<int> seq = {b};
  while (b > a) {
    if ((b & 1) == 0) {
      b /= 2;
    } else if (b % 10 == 1) {
      b /= 10;
    } else {
      break;
    }
    seq.push_back(b);
  }

  if (b != a) {
    cout << "NO" << "\n";
  } else {
    cout << "YES" << "\n" << seq.size() << "\n";
    for (int i = seq.size()-1; i >= 0; i--) {
      cout << seq[i] << " ";
    }
  }
}