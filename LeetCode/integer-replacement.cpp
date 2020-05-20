#include <iostream>
#include <unordered_map>
using namespace std;
using int64 = long long int;

class Solution {
private:
  int64 integerReplacement(int n, unordered_map<int64, int64>& memo) {
    if (n == 1) return 0;
    if (n == 2147483647) return 32;
    if (n % 2 == 0) {
       return 1 + integerReplacement(n/2);
    }
    if (memo.count(n)) return memo[n];
    int64 a, b;
    a = 1 + integerReplacement(n - 1);
    b = 1 + integerReplacement(n + 1);
    memo[n] = min(a,b);
    return memo[n];
  }
public:
  int integerReplacement(int n) {
    unordered_map<int64, int64> memo;
    return integerReplacement(n, memo);
  }
};

int main(void) {
  return 0;
}