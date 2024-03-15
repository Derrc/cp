#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  // redirects stdin to input file
  freopen("paint.in", "r", stdin);
  // redirects stdout to write to output file
  freopen("paint.out", "w", stdout);

  int a, b, c, d;
  int painted = 0;
  vector<bool> fences(100);

  cin >> a >> b >> c >> d;

  for (int i=a; i < b; i++) {
    fences[i] = true;
  }

  for (int i=c; i < d; i++) {
    fences[i] = true;
  }

  for (int i = 0; i <= 100; i++) {
    if (fences[i]) {
      painted++;
    }
  }

  cout << painted;
}