#include <iostream>
#include <vector>
#include <string>
using namespace std;

// brute force recursion:
// keep track of character counts so that we can find permutations in lexographic order
// prevents creating permutations with duplicate chars as well since function is only called once for char (one branch for each char)

string str;
vector<string> permutations;
vector<int> char_counts(26);

void search(const string &cur) {
  if (cur.size() == str.size()) {
    permutations.push_back(cur);
  }

  for (int i = 0; i < 26; i++) {
    if (char_counts[i] > 0) {
      char_counts[i]--;
      search(cur + char('a'+i));
      char_counts[i]++;
    }
  }
}

int main() {
  cin >> str;

  for (char c : str) {
    // ascii value operation to get char index
    char_counts[c-'a']++;
  }

  search("");

  cout << permutations.size() << "\n";

  for (string s : permutations) {
    cout << s << "\n";
  }
}