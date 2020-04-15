#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.size() == 0) return {};
    print(nums);
    vector<int> left_right(nums.size());
    left_right[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      left_right[i] = left_right[i - 1] * nums[i];
    }
    print(left_right);
    vector<int> right_left(nums.size());
    right_left[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--) {
      right_left[i] = right_left[i + 1] * nums[i];
    }
    print(right_left);
    vector<int> result(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      int left = (i - 1 >= 0 ? left_right[i - 1] : 1);
      int right = (i + 1 < nums.size() ? right_left[i + 1] : 1);
      result[i] = left * right;
    }
    print(result);
    return result;
  }
private:
  void print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }
};

int main(void) {
  vector<int> nums = {1,2,3,4};
  Solution sol;
  sol.productExceptSelf(nums);
  return 0;
}