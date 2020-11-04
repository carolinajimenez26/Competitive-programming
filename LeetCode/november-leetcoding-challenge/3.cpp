#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxPower(string s) {
    if (s.empty()) return 0;
    int best = 1;
    int i = 0;
    while (i < s.size()) {
      if (i + 1 < s.size() && s[i] == s[i + 1]) {
        int times = 0;
        char c = s[i];
        while (s[i] == c) {
          times++;
          i++;
        }
        best = max(best, times);
        i--;
      }
      i++;
    }
    return best;
  }
};

struct Test {
  string s;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    {"leetcode", 2},
    {"abbcccddddeeeeedcba", 5},
    {"eeabbcccddddeeeeedcba", 5},
    {"triplepillooooow", 5},
    {"hooraaaaaaaaaaay", 11},
    {"tourist", 1},
    {"", 0},
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.maxPower(test.s);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out 
           << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}