#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
#define dbg(x) cout << setprecision(10) << #x << ": " << x << endl

class Solution {
public:
  bool cmp(double x, double y) {
    const double eps = 1e-10;
    return abs(x - y) <= eps;
  }
  
  bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    double x = (log(n) / log(3));
    double y = round(log(n) / log(3));
    dbg(x); dbg(y);
    return cmp(x, y);
  }
};

struct Test {
  int n;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    { -1, false },
    { 1, true },
    { 3, true },
    { 243, true },
    { 45, false },
    { 1594322, false }
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.isPowerOfThree(test.n);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out 
           << ", expected " << test.expected << " for number " << test.n << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}