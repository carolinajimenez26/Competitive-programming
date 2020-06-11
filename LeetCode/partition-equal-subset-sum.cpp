#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  bool canPartition(const vector<int>& nums, int idx, int acc, int sum,
    vector<vector<int>>& memo) {
    if (acc == sum) {
      memo[idx][acc] = true;
      return memo[idx][acc];
    }
    if (idx >= nums.size()) {
      memo[idx][acc] = acc == sum;
      return memo[idx][acc];
    }
    if (acc > sum) {
      memo[idx][acc] = false;
      return memo[idx][acc];
    }
    if (memo[idx][acc] != -1) {
      return memo[idx][acc];
    }
    bool op1 = canPartition(nums, idx + 1, acc + nums[idx], sum, memo);
    bool op2 = canPartition(nums, idx + 1, acc, sum, memo);
    memo[idx][acc] = op1 || op2;
    return memo[idx][acc];
  }

public:
  bool canPartition(vector<int> &nums) {
    int MAX = 100 * 200 + 1;
    vector<vector<int>> memo(nums.size() + 1, vector<int>(MAX, -1));
    int sum = 0;
    for (auto e : nums) sum += e;
    if (sum % 2 != 0) return false;
    return canPartition(nums, 0, 0, sum / 2, memo);
  }
};

struct Test {
  vector<int> nums;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {1,5,11,5},
      true
    },
    {
      {1,2,3,5},
      false
    },
    {
      {1,2,3,5,5},
      true
    },
    {
      {5,5,1,5},
      false
    },
    {
      {3,3,3,4,5},
      true
    }
  };

  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    if (sol.canPartition(test.nums) != test.expected) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }
  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;
  return 0;
}