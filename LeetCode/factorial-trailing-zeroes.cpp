#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    if (n == 0) return 0;
    int amount_of_2 = GetNumbersOfXInN(2, n);
    int amount_of_5 = GetNumbersOfXInN(5, n);
    return min(amount_of_2, amount_of_5);
  }
private:
  int GetNumbersOfXInN(int x, int n) {
    // x^k > n
    int k = log(n) / log(x);
    int ans = 0;
    for (int i = 1; i <= k; i++) {
      int exp = pow(x, i);
      ans += (n / exp);
    }
    return ans;
  }
};

int main(void) {
  Solution sol;
  cout << sol.trailingZeroes(6) << endl;
  return 0;
}