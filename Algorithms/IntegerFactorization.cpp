// See https://cp-algorithms.com/algebra/factorization.html
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// op1, when we have few numbers to calculate its divisors
// if we call this function from 1 to n, the runtime complexity would be:
// sqrt(1) + sqrt(2) + ... + sqrt(n) = O(sqrt(n^3))
vector<int> FindDivisors(int n) {
  vector<int> factorization; // we can also use a hash table to have less memory usage
  for (long long d = 2; d * d <= n; d++) { // sqrt(n) is the worst case
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
  }
  if (n > 1) factorization.push_back(n);
  return factorization;
}

// O(n log log n)
vector<int> Sieve(int n) {
  vector<int> primes;
  vector<bool> sieve(sqrt(n), true);
  sieve[0] = sieve[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (sieve[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= n; j += i) {
        sieve[j] = false;
      }
    }
  }
  return primes;
}

// O (n / log n)
// if we call this for multiple n, we have:
// Sieve: n log log n
// FindDivisors: n / log n
// so: n log log n + n / log n = O(n log log n)
// which is smaller than O(sqrt(n^3))
vector<int> FindDivisors(int n, const vector<int>& primes) {
  vector<int> factorization;
  for (long long d : primes) { // the amount of primes from 1 to n is (n / log n)
    if (d * d > n) break;
    while (n % d == 0) {
      factorization.push_back(d); // we can use a hash table here too
      n /= d;
    }
  }
  if (n > 1) factorization.push_back(n);
  return factorization;
}

int main(void) {
  return 0;
}