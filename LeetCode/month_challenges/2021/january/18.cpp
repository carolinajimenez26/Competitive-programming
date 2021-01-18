#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> freqs;
    for (auto e : nums) {
      freqs[e]++;
    }
    int ans = 0;
    for (auto e : nums) {
      if (freqs[e] == 0) {
        continue;
      }
      // nums[i] + x = k ==> x = k - nums[i]
      int x = k - e;
      freqs[e]--;
      if (freqs[x] > 0) {
        ans++;
        freqs[x]--;
      } else {
        freqs[e]++;
      }
    }
    return ans;
  }
};

struct Test {
  vector<int> nums;
  int k;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,2,3,4}, 5, 2 },
    { {3,1,3,4,3}, 6, 1 },
    { {}, 2, 0 },
    { {1,2,3}, 1, 0 },
    { {2,2,2,2,2}, 4, 2 },
    { {2,2,2,2}, 4, 2 },
    { {2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2}, 3, 4 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.maxOperations(test.nums, test.k);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}