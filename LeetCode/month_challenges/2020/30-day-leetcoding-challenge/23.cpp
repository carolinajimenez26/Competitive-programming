#include <iostream>
#include <cmath>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    if (m == n) return m;
    int result = m & n;
    int copy = result;
    int i = 0, x = 1;
    while (copy > 0) {
      int a = m & x;
      int b = n & x;
      a >>= i;
      b >>= i;
      if (a == b) { // both have the same bit i
        int y = Generate(n, i);
        // dbg(y);
        if (m <= y && y <= n) {
          result &= y;
        }
      }
      i++;
      x <<= 1;
      copy >>= 1;
    }
    return result;
  }
private:
  int Generate(int n, int position) {
    int mask = 1 << position;
    return n ^ mask;
  }
};

int main(void) {
  Solution sol;
  cout << sol.rangeBitwiseAnd(12,15) << endl; // 12
  cout << sol.rangeBitwiseAnd(200,214) << endl; // 192
  return 0;
}