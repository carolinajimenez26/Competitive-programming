#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<bool> CalcMinToLeft(const vector<int>& nums) {
    vector<bool> left_to_right(nums.size(), false);
    int best = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > best) {
        left_to_right[i] = true;
      }
      best = min(best, nums[i]);
    }
    return left_to_right;
  }

  vector<bool> CalcMaxToRight(const vector<int>& nums) {
    vector<bool> right_to_left(nums.size(), false);
    int best = nums.back();
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < best) {
        right_to_left[i] = true;
      }
      best = max(best, nums[i]);
    }
    return right_to_left;
  }
public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() <= 2) return false; 
    vector<bool> left_to_right = CalcMinToLeft(nums);
    vector<bool> right_to_left= CalcMaxToRight(nums);

    for (int i = 0; i < nums.size(); i++) {
      if (left_to_right[i] && right_to_left[i]) return true;
    }
    return false;
  }
};

struct Test {
  vector<int> nums;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,2,3,4,5}, true },
    { {5,4,3,2,1}, false },
    { {2,1,5,0,4,6}, true },
    { {5,3,4,6}, true },
    { {}, false },
    { {1,1,1,1}, false },
    { {1,2}, false },
    { {1,1,1,-1,-2,-3,2}, false },
    { {1,1,2,-1,-2,-3}, false },
    { {1,1,2,-1,-2,-3,3}, true },
    { {2,1,5,0,3}, false },
    { {5,1,5,5,2,5,4}, true },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.increasingTriplet(test.nums);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}

