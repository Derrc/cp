#include <iostream>
#include <vector>
using namespace std;

/*
  - Count number of divisors in O(n * root(x)) time
  - Better way in O((n+x)log(x)) -> xlog(x) preprocessing followed by log(x) to get divisors per number
  - Sieve of Eratosthenes to get arr where arr[i] = largest prime number that divides i
  - divide repeatedly by arr[i] until i == 1 -> gets prime factorization in O(log x) time since x can have at most O(log x) distinct prime factors
*/

const int MAX_N = 1e6;

int num_divisors(int n) {
  int count = 0;
  // check divisors from 1 -> root(n)
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      // check for case where n is a perfect square so divisor is the same number twice
      count += i * i == n ? 1 : 2;
    }
  }

  return count;
}

int main() {
  vector<int> primes(MAX_N+1);
  // Sieve of Eratosthenes
  for (int i = 2; i <= MAX_N; i++) {
    if (primes[i] == 0) {
      for (int j = i; j <= MAX_N; j += i) {
        primes[j] = i;
      }
    }
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    int divisors = 1;
    while (num != 1) {
      // how many times current prime factor divides into num
      int n_factor = 0;
      // current prime factor
      int prime = primes[num];
      while (num % prime == 0) {
        num /= prime;
        n_factor++;
      }

      divisors *= n_factor + 1;
    }

    cout << divisors << "\n";
  }
}