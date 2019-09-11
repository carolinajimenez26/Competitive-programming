#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxSubArray(const vector<int>& nums, int curr_idx, int curr_val) {
    if (curr_idx >= nums.size()) {
      return curr_val;
    }
    int a = maxSubArray(nums, curr_idx + 1, curr_val + nums[curr_idx]);
    int b = maxSubArray(nums, curr_idx + 1, nums[curr_idx]);
    return max(max(a, b), curr_val);
  }

  void maxSubArrayDP(const vector<int>& nums, int curr_idx, vector<int>& memo) {
    if (curr_idx >= nums.size()) {
      return;
    }

    int best = 0;
    if (curr_idx - 1 >= 0) best = max(best, nums[curr_idx] + memo[curr_idx - 1]);
    best = max(best, nums[curr_idx]);
    memo[curr_idx] = best;
    maxSubArrayDP(nums, curr_idx + 1, memo);
  }

  int maxSubArray(vector<int>& nums) {
    if (nums.size () == 0) return 0;
    vector<int> memo(nums.size(), -1);
    maxSubArrayDP(nums, 0, memo);
    int max_n = *max_element(memo.begin(), memo.end());
    if (max_n == 0) {
      return *max_element(nums.begin(), nums.end());
    }
    return max_n;
  }
};

int main(void) {
  Solution sol;
  vector<int> input = {-2,1,-3,4,-1,2,1,-5,100};
  cout << sol.maxSubArray(input) << endl;
  return 0;
}
