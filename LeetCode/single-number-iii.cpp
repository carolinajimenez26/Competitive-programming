#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
  vector<int> result;
  if (nums.size() == 0) return result;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size();) {
    if (i + 1 >= nums.size()) {
      return result.push_back(nums[i]);
    }
    if (i + 1 < nums.size() && nums[i] != nums[i + 1]) {
      result.push_back(nums[i]);
      i++;
    } else {
      i += 2;
    }
  }
  return result;
}

int main(void) {
  vector<int> input = {1,2,1,3,2,5};
  singleNumber(input);
  return 0;
}
