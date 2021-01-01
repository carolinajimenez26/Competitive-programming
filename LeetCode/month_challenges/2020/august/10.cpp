#include <iostream>
#include <vector>
using namespace std;
using int64 = long long int;

class Solution {
public:
  int titleToNumber(string s) {
    int64 ans = 0;
    int64 x = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      int n = s[i] - 'A' + 1;
      ans += (x * n);
      x *= 26;
    }
    return ans;
  }
};

struct Test {
  string in;
  int ans;
};

int main(void) {
  vector<Test> tests = {
    { "A", 1 },
    { "B", 2 },
    { "Z", 26 },
    { "AA", 27 },
    { "BA", 53 },
    { "ZA", 677 },
    { "ZY", 701 },
    { "ZZZ", 18278 },
    { "FXSHRXW", 2147483647 }
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int out = sol.titleToNumber(test.in);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}