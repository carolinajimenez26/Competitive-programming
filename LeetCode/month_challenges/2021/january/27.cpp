#include <iostream>
using namespace std;

using int64 = long long int;
class Solution {
public:
  int concatenatedBinary(int n) {
    const int mod = 1e9 + 7;
    int64 ans = 0;
    for (int i = 1; i <= n; i++) {
      int64 times = log2(i) + 1;
      ans <<= times;
      ans |= i;
      ans %= mod;
    }
    return (ans % mod);
  }
};

int main(void) {
  Solution sol;
  cout << sol.concatenatedBinary(12) << endl;
  return 0;
}