#include <iostream>
#include <vector>
using namespace std;

/*
  Number of swaps to sort array
  - find mutually exclusive cycles
  - min number of swaps for a cycle of size k is k-1
*/

int main() {
  int n;
  cin >> n;

  // element at index i should be at index position[i], i -> position[i]
  vector<int> position(n);
  for (int i = 0; i < n; i++) {
    cin >> position[i];
    position[i]--;
  }

  int swaps = 0;
  for (int i = 0; i < n; i++) {
    // i is pivot index
    int j = position[i];
    // swap until cycle repeats (position[i] = i)
    while (i != j) {
      // swap element at index i to correct position
      swap(position[i], position[j]);
      // now position[i] contains next index in cycle
      j = position[i];
      swaps++;
    }
  }

  cout << swaps << endl;
}