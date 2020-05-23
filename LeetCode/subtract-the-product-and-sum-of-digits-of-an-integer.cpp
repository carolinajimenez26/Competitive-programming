#include <iostream>
using namespace std;

class Solution {
private:
  int MultiplyDigitis(int n) {
    int ans = 1;
    while (n > 0) {
      int digit = n % 10;
      n /= 10;
      ans *= digit;
    }
    return ans;
  }
  int SumDigits(int n) {
    int ans = 0;
    while (n > 0) {
      int digit = n % 10;
      n /= 10;
      ans += digit;
    }
    return ans;
  }
public:
  int subtractProductAndSum(int n) {
    int mult = MultiplyDigitis(n);
    int sum = SumDigits(n);
    return mult - sum;
  }
};

int main(void) {
  Solution sol;
  cout << sol.subtractProductAndSum(234) << endl;
  cout << sol.subtractProductAndSum(4421) << endl;
  return 0;
}