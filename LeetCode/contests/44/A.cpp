#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int largestAltitude(vector<int>& gain) {
    int best = 0;
    int acc = 0;
    for (auto e: gain) {
      acc += e;
      best = max(best, acc);
    }   
    return best;
  }
};

struct Test {
  vector<int> gain;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {-5,1,5,0,-7}, 1 },
    { {-4,-3,-2,-1,4,3,2}, 0 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.largestAltitude(test.gain);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}