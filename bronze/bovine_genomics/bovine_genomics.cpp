#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// brute force: O(n^2 * m)
// iterate over all genome positions and add all chars found in spotted cows to an array
// then iterate over plain cows and check if any chars already exist in spotted array
// if yes then this position cannot be used, if no then it can be used

// using hashset: O(n*m)
// O(1) count operation to check if given value is in set or not

int contains(const vector<char> &vec, const char &target) {
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == target) {
      return true;
    }
  }

  return false;
}

int main() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int cows_n, genome_len;
  cin >> cows_n >> genome_len;

  vector<vector<char>> genomes(2*cows_n, vector<char>(genome_len));

  for (int c = 0; c < 2*cows_n; c++) {
    for (int pos = 0; pos < genome_len; pos++) {
      cin >> genomes[c][pos];
    }
  }

  int positions = 0;
  for (int pos = 0; pos < genome_len; pos++) {
    unordered_set<char> seen(cows_n);
    bool good = true;
    // iterate through spotted cows and keep track of encountered chars
    for (int c = 0; c < cows_n; c++) {
      seen.insert(genomes[c][pos]);
    }

    // iterate through plain cows and check if char was already seen in a spotted cow
    for(int c = cows_n; c < 2*cows_n; c++) {
      if (seen.count(genomes[c][pos]) == 1) {
        good = false;
        break;
      }
    }

    positions += good;
  }

  cout << positions;
}