#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int pivot_idx = nums.size() / 2;
    int result = 0;
    for (auto e : nums) {
      result += abs(e - nums[pivot_idx]);
    }
    return result;
  }
};

int main(void) {
  return 0;
}