#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    if (nums.size() == 0) return false;
    if (nums.size() == 1) return true;
    return CanJump(nums, nums.size() - 2, 1);
  }
private:
  bool CanJump(const vector<int>& v, int i, int len) {
    if (i == 0) {
      return v[i] >= len;
    }
    if (v[i] >= len) {
      return CanJump(v, i - 1, 1);
    }
    return CanJump(v, i - 1, len + 1);
  }
};

int main(void) {
  vector<int> v = {1,1,2,3,0,0,4};
  Solution sol;
  cout << sol.canJump(v) << endl;
  return 0;
}