#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> nums;
public:
  int BinarySearch(int left, int right, int target) {
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }

  int FindFirstOccurrance(int left, int right, int target) {
    while (left <= right) {
      int mid = (left + right) / 2;
      if (mid - 1 >= 0 && nums[mid - 1] < target && nums[mid] == target) {
        return mid;
      }
      if (nums[mid] == target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }

  int FindLastOccurrance(int left, int right, int target) {
    while (left <= right) {
      int mid = (left + right) / 2;
      if (mid + 1 < nums.size() && nums[mid + 1] > target && nums[mid] == target) {
        return mid;
      }
      if (nums[mid] == target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }

  vector<int> searchRange(vector<int>& nums_, int target) {
    nums = nums_;
    int first_target = -1, last_target = -1;
    int idx_target = BinarySearch(0, nums.size() - 1, target);
    if (idx_target == -1) { // if target does not exists in array
      return {-1,-1};
    }
    // 111222333444 if we were looking for the first occurrence of 4,
    // we could go and search for the first element that is not 4 and has a 
    // 4 on its right
    first_target = FindFirstOccurrance(0, idx_target, target);
    if (first_target == -1) { // the firsts elements are our target
      first_target = 0;
    }
    // 44444555667788 the same but now we are looking for the first number
    // with our target (let's say 4) on its left
    last_target = FindLastOccurrance(idx_target, nums.size() - 1, target);
    if (last_target == -1) {
      last_target = nums.size() - 1;
    }

    return {first_target, last_target};
  }
};

int main(void) {
  vector<int> input = {5,7,7,8,8,10};
  int target = 8;
  Solution sol;
  vector<int> out = sol.searchRange(input, target);
  cout << out[0] << ", " << out[1] << endl;
  return 0;
}
