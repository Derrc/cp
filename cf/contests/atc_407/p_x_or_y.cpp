#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int sum = 0;
    int diff = 0;
    int both = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j >= x) {
                sum++;
            }
            if (abs(i - j) >= y) {
                diff++;
            }
            if (i + j >= x && abs(i - j) >= y) {
                both++;
            }
        }
    }

    cout << setprecision(10) << (double)(sum + diff - both) / 36 << endl;
}