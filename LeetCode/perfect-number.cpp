#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;

using int64 = long long int;
class Solution {
public:
  bool checkPerfectNumber(int num) {
    if (num <= 1) {
      return false;
    }
    vector<int> primes = GetPrimes(num);
    // Print(primes);
    unordered_map<int,int> divisors = GetDivisors(num, primes);
    // Print(divisors);
    int sum = 1;
    // O (divisors.size())
    for (auto [prime, times] : divisors) {
      int partial = (pow(prime, times + 1) - 1) / (prime - 1);
      sum *= partial;
    }
    sum -= num;
    return sum == num;
  }
private:
  const int MAX = 1e8 + 5;

  void Print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }

  void Print(const unordered_map<int,int>& hash_table) {
    for (auto [key,val] : hash_table) {
      cout << key << "->" << val << endl;
    }
  }

  // O(n log log n)
  vector<int> GetPrimes(int num) {
    vector<int> primes;
    vector<bool> sieve(sqrt(MAX), true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
      if (!primes.empty() && primes.back() >= num) {
        break;
      }
      if (sieve[i]) {
        primes.push_back(i);
        for (int64 j = i * i; j * j <= MAX; j += i) {
          sieve[j] = false;
        }
      }
    }
    primes.pop_back();
    return primes;
  }

  // O (n / log n)
  unordered_map<int,int> GetDivisors(int n, const vector<int>& primes) {
    unordered_map<int, int> factorization;
    for (long long d : primes) { // the amount of primes from 1 to n is (n / log n)
      if (d * d > n) break;
      while (n % d == 0) {
        factorization[d]++;
        n /= d;
      }
    }
    if (n > 1) factorization[n]++;
    return factorization;
  } 
};

struct Test {
  int num;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    { 0, false },
    { 1, false },
    { 2, false },
    { 6, true },
    { 28, true },
    { 496, true },
    { 8128, true },
    { 2016, false },
    { 24, false },
    { 100000000, false },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.checkPerfectNumber(test.num);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}