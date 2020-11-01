#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
  // Space: O(1)
  // Runtime: O((n log n) + n) = O(n log n)
  bool containsDuplicate1(vector<int>& nums) {
    if (nums.empty()) return false;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) return true;
    }
    return false;
  }
  // Space: O(n)
  // Runtime: O(n)
  bool containsDuplicate(vector<int>& nums) {
    if (nums.empty()) return false;
    unordered_set<int> seen;
    for (auto e : nums) {
      if (seen.count(e) != 0) return true;
      seen.insert(e);
    }
    return false;
  }
};

int main(void) {
  return 0;
} 
