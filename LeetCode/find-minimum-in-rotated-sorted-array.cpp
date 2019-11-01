#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int BinarySearch(int left, int right, const vector<int>& nums) {
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[left] < nums[right]) {
        return left; // there is no rotation at all
      }
      if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) { // found rotation point
        return mid;
      }
      if (nums[mid] < nums[right]) { // if this part is OK
        right = mid - 1; // go find in the left
      } else {
        left = mid + 1; // go find in the right
      }
    }
    return left;
  }

  int findMin(vector<int>& nums) {
    return nums[BinarySearch(0, nums.size() - 1, nums)];
  }
};

/*
Test cases:
[1,2,3,4,5,6,7,8,9,10]
[8,9,10,1,2,3,4,5,6,7]
[5,6,7,8,9,10,1,2,3,4]
[1,2]
[2,1]
[1]
[1,2,3]
[3,1,2]
*/

int main(void) {
  return 0;
}
