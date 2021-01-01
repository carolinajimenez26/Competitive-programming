#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
    if (time.empty()) return 0;
    int ans = 0;
    unordered_map<int, int> seen; // elem -> freq
    seen[time[0]] = 1;
    for (int i = 1; i < time.size(); i++) {
      // time[i] + x = y * 60

      // max sum between 2 elements in time is 1000 because every number in time is at most 500
      // num * 60 <= 1000  -->  num <= (1000 / 60)  --> num <= 16.666
      for (int y = 1; y <= 17; y++) {
        int x = y * 60 - time[i];
        if (seen.count(x)) {
          ans += seen[x];
        }
      }
      seen[time[i]]++;
    }
    return ans;
  }
};

struct Test {
  vector<int> time;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {30,20,150,100,40}, 3 },
    { {60,60,60}, 3 },
    { { 20, 10, 30 }, 0 },
    { { 100, 40, 20, 10, 30 }, 2 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.numPairsDivisibleBy60(test.time);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " 
           << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}