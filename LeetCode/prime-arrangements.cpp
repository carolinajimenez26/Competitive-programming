#include <iostream>
#include <vector>
using namespace std;

using int64 = long long int;
class Solution {
public:
  // n sqrt(n)
  int numPrimeArrangements(int n) {
    int primes = CountPrimes(n);
    int not_primes = n - primes;
    fact_memo.assign(n, -1);
    int64 primes_fact = GetFactorial(primes);
    int64 not_primes_fact = GetFactorial(not_primes);
    int64 ans = (primes_fact * not_primes_fact) % mod;
    return ans;
  }
private:
  const long long int mod = 1e9 + 7;
  vector<int64> fact_memo;

  // n
  int64 GetFactorial(int n) {
    if (n <= 1) return 1;
    if (fact_memo[n] != -1) return fact_memo[n];
    int64 next = GetFactorial(n - 1) % mod;
    fact_memo[n] = (n * next) % mod;
    return fact_memo[n];
  }

  // sqrt(n)
  bool IsPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
    }
    return true;
  }

  // n sqrt(n)
  int CountPrimes(int n) {
    int ans = 0;
    for (int i = 2; i <= n; i++) { // n
      if (IsPrime(i)) { // sqrt(n)
        ans++;
      }
    }
    return ans;
  }
};

int main(void) {
  Solution sol;
  cout << sol.numPrimeArrangements(5) << endl;
  cout << sol.numPrimeArrangements(20) << endl;
  cout << sol.numPrimeArrangements(100) << endl;
  return 0;
}