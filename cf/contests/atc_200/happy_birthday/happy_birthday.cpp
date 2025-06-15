#include <iostream>
#include <vector>
using namespace std;

// Pigeonhole principle: for a group of 201 sequences, at least one pair of sequences must have the same sum % 200
// We only have to check max 2^8 sequences to find a matching pair
// Use bitmasks to get sum of all possible subsets (minus empty set)

int a[205];
// sum % 200 -> seq indices
vector<int> bm[205];
int minN = -1;

void print(vector<int> &arr) {
  cout << arr.size() << " ";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  minN = min(n, 8);
  for (int m = 1; m < (1 << minN); m++) {
    int sum = 0;
    vector<int> mArr;
    for (int i = 0; i < minN; i++) {
      if (m & (1 << i)) {
        sum = (sum + a[i]) % 200;
        mArr.push_back(i + 1);
      }
    }

    if (bm[sum].size() != 0) {
      cout << "Yes" << "\n";
      print(bm[sum]);
      print(mArr);
      return 0;
    }

    bm[sum] = mArr;
  }

  cout << "No" << endl;
}