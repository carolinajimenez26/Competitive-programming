#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

using int64 = long long int;
class Solution {
private:
  bool IsNegative(int64 n) {
    return n < 0 ? true : false;
  }

  // -,- = +  => 0,0 = 1
  // -,+ = -  => 0,1 = 0
  // +,- = -  => 1,0 = 0
  // +,+ = +  => 1,1 = 1
  bool IsNegative(int64 a, int64 b) {
    bool a_sign = IsNegative(a);
    bool b_sign = IsNegative(b);
    return !(a_sign ^ b_sign);
  }

  void ChangeSign(int64& n) {
    bool sign = IsNegative(n);
    if (sign) { // less than 0
      // -x + z = x
      // z = x + x
      n = n - n + (-n);
    } else {
      // x + z = -x
      // z = -x - x
      n = n - n - n;
    }
  }

  int Divide(int64 dividend, int64 divisor, int64& ans) {
    bool sign = IsNegative(divisor, dividend);
    if (IsNegative(dividend)) {
      ChangeSign(dividend);
    }
    if (IsNegative(divisor)) {
      ChangeSign(divisor);
    }
    if (dividend == 0 || divisor > dividend) return 0;
    if (divisor == 1) {
      if (!IsNegative(dividend) && sign == false) {
        ChangeSign(dividend);
      }
      ans = dividend;
      return ans;
    }

    vector<int64> powers_of_2, count;
    count.push_back(divisor); // 2^0 * divisor
    powers_of_2.push_back(1); // 2^0
    int i = 0;
    while (count[i] <= dividend) {
      int64 x = count.back() + count.back();
      if (x > dividend) {
        break;
      }
      count.push_back(x); // 2^i * divisor
      int64 y = powers_of_2.back() + powers_of_2.back();
      powers_of_2.push_back(y);
      i++;
    }
    ans = powers_of_2.back();
    dividend -= count.back();
    while (i >= 0) {
      if (count[i] <= dividend) {
        ans += powers_of_2[i];
        dividend -= count[i];
      }
      i--;
    }

    if ((IsNegative(ans) && sign == true) || (!IsNegative(ans) && sign == false)) {
      ChangeSign(ans);
    }
    return ans;
  }
public:
  int divide(int dividend, int divisor) {
    const int MAX = numeric_limits<int>::max();
    int64 ans = 0;
    int ans32bits = Divide(dividend, divisor, ans);
    if (ans32bits != ans) {
      return MAX;
    }
    return ans;
  }

  void Test() {
    dbg(IsNegative(-2));
    dbg(IsNegative(-1));
    dbg(IsNegative(0));
    dbg(IsNegative(1));
    dbg(IsNegative(2));
    int64 a = 7;
    dbg(a);
    ChangeSign(a);
    dbg(a);
    int64 b = -3;
    dbg(b);
    ChangeSign(b);
    dbg(b);
  }
};

int main(void) {
  Solution sol;
  // sol.Test();
  cout << sol.divide(7,3) << endl;
  cout << sol.divide(3,3) << endl;
  cout << sol.divide(0,3) << endl;
  cout << sol.divide(8,3) << endl;
  cout << sol.divide(7,-3) << endl;
  cout << sol.divide(-2147483648,-1) << endl;
  cout << sol.divide(1,2) << endl;
  cout << sol.divide(28, 7) << endl;
  cout << (sol.divide(2147483647,3) == 715827882 ? "Correct" : "Incorrect") << endl;
  return 0;
}