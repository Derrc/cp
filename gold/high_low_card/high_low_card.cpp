#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
  Greedy
  - for high cards: sort cards in descending order, play highest card that can beat their highest card
  - if we can't beat highest card, we continue (same as playing worst card (i.e. lowest card in first n/2 highest cards)
  - for low cards: sort cards in ascending order, play lowest card that can beat their lowest card
*/

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  freopen("cardgame.in", "r", stdin);
  freopen("cardgame.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> cards_high(n/2);
  vector<int> cards_low(n/2);
  unordered_set<int> numbers;
  vector<int> bcards;

  for (int i = 0; i < n/2; i++) {
    int next;
    cin >> next;
    cards_high[i] = next;
    numbers.insert(next);
  }

  for (int i = 0; i < n/2; i++) {
     int next;
    cin >> next;
    cards_low[i] = next;
    numbers.insert(next);
  }

  for (int i = 1; i <= 2*n; i++) {
    if (numbers.count(i) > 0) {
      continue;
    }

    bcards.push_back(i);
  }


  // high card game
  sort(cards_high.begin(), cards_high.end(), cmp);
  sort(bcards.begin(), bcards.end(), cmp);

  int points = 0;
  int cur = 0;
  for (int i = 0; i < n/2; i++) {
    if (cards_high[i] > bcards[cur]) {
      continue;
    }

    points += 1;
    cur++;
  }

  // low card game
  sort(cards_low.begin(), cards_low.end());

  cur = n-1; // iterate in reverse from [n-1, n/2]
  for (int i = 0; i < n/2; i++) {
    if (cards_low[i] < bcards[cur]) {
      continue;
    }

    points += 1;
    cur--;
  }

  cout << points;
}