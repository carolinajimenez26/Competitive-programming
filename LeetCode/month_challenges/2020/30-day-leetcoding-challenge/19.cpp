#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int breaking_idx = BinarySearchLessThan(nums[0], nums, 0, nums.size() - 1);
    int found_idx = -1;
    found_idx = BinarySearch(target, nums, 0, breaking_idx - 1);
    if (found_idx != -1) return found_idx;
    found_idx = BinarySearch(target, nums, breaking_idx, nums.size() - 1);
    return found_idx;
  }
private:
  int BinarySearchLessThan(int target, const vector<int>& nums, int left, int right) {
    while (left < right) {
      int mid = (left + right + 1) / 2;
      if (nums[mid] >= target) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    return left + 1;
  }
  int BinarySearch(int target, const vector<int>& nums, int left, int right) {
    while (left >= 0 && left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};

int main(void) {
  vector<int> v = {1};
  Solution sol;
  cout << sol.search(v, 1) << endl;
  return 0;
}