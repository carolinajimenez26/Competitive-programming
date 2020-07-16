#include <iostream>
#include <vector>
using namespace std;
using int64 = long long int;
/*
  x^n = {
    (x^2)^(n/2)          if even
    ((x^2)^(n/2)) * x    if odd
  }
*/
class Solution {
private:
  double FastPow(double x, int64 n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n % 2 == 0) return FastPow(x * x, n / 2);
    return x * FastPow(x * x, n / 2);
  }

public:
  double myPow(double x, int64 n) {
    if(n < 0) return 1.0 / FastPow(x, -n);
    return FastPow(x, n);
  }
};

struct Test {
  double x;
  int n;
  double ans;
};

int main(void) {
  vector<Test> tests = {
    { 4, 5, 1024 },
    { 2, 6, 64 }, 
    { 2, 10, 1024 }, 
    // { 2.1, 3, 9.26100 },
    { 2.00000, -2, 0.25000 },
    { 11, 0, 1 },
    { 0, 0, 1 },
    { 0, 5, 0 },
    { 1, 2147483647, 1},
    // { 10, 2147483647, inf },
    { 0.00001, 2147483647, 0 },
    { 2, 10, 1024 },
    { 1.00000, -2147483648, 1}
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    double out = sol.myPow(test.x, test.n);
    if (test.ans != out) {
      cout << "Failed on test #" << tc << ". Found: " << out << ", expected: " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}