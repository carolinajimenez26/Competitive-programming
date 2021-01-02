#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> freqs;
    int ans = 0;
    for (auto num : nums) {
      ans += freqs[num];
      freqs[num]++;
    }
    return ans;
  }
};

struct Test {
  vector<int> nums;
  int expected;
};  

int main(void) {
  vector<Test> tests = {
    { {}, 0 },
    { {1}, 0 },
    { {1,1}, 1 },
    { {1,2}, 0 },
    { {1,1,1}, 3 },
    { {1,1,1,1}, 6 },
    { {1,2,3,1,1,3}, 4 },
  };

  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.numIdenticalPairs(test.nums);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}