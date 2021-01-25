#include <iostream>
#include <vector>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

class Solution {
public:
  bool kLengthApart(vector<int>& nums, int k) {
    int left, right;
    right = left = 0;
    while (left < nums.size()) {
      right = Skip(nums, left, 1);
      if ((right - left) > 1 && k != 0) {
        return false;
      }
      if (right >= nums.size()) {
        return true;
      }
      left = right;
      right = Skip(nums, left, 0);
      if (right >= nums.size()) {
        return true;
      }
      if ((right - left) < k) {
        return false;
      }
      left = right;
    }
    return true;
  }
private:
  int Skip(const vector<int>& nums, int from, int target) {
    int i = from;
    while (i < nums.size() && nums[i] == target) {
      i++;
    }
    return i;
  }
};

struct Test {
  vector<int> nums;
  int k;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,0,0,0,1,0,0,1}, 2, true },
    { {1,0,0,0,1,0,1}, 2, false },
    { {1,0,0,0,1,0,0,1}, 3, false },
    { {0,0,0,1,0,0,1}, 2, true },
    { {0,0,0,1,0,0}, 2, true },
    { {0,0,0,0,0}, 2, true },
    { {0,0,0,0,1}, 2, true },
    { {1,0,0,0,1}, 4, false },
    { {1,0,0,0,0}, 2, true },
    { {1,1,0,0,0}, 0, true },
    { {1,0,0,1,0}, 0, true },
    { {1,1}, 1, false },
    { {1,0,0,1,0,1}, 2, false },
    { {1,1,1,1,1}, 0, true },
    { {0,1,0,1}, 1, true },
    { {1,0,0,0,1,0,0,1,0}, 2, true }
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.kLengthApart(test.nums, test.k);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}