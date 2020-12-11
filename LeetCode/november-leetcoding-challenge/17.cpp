#include <iostream>
#include <numeric>
using namespace std;

class Solution {
private:
  inline bool IsEven(const int num) {
    return (num % 2) == 0;
  }
public:
  int mirrorReflection(int p, int q) {
    int _lcm = lcm(p,q);
    int steps = (_lcm / q);
    int final_y = _lcm / p;
    int final_x = steps;
    if (IsEven(final_x) && !IsEven(final_y)) {
      return 2;
    }
    if (!IsEven(final_x) && IsEven(final_y)) {
      return 0;
    }
    if (!IsEven(final_x) && !IsEven(final_y)) {
      return 1;
    }
    return -1; // IsEven(final_x) && IsEven(final_y), this can never happen
  }
};

int main(void) {
  Solution sol;
  cout << sol.mirrorReflection(2,1) << endl;
  return 0;
}