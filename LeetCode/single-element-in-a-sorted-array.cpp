#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

bool isDifferent(const vector<int>& nums, int index) {
  bool op1 = true, op2 = true;
  if (index - 1 >= 0) {
    op1 = nums[index] != nums[index - 1];
  }
  if (index + 1 < nums.size()) {
    op2 = nums[index] != nums[index + 1];
  }
  return op1 && op2;
}

// O (log(nums.size())) time
// O (log(nums.size())) memory
int search(const vector<int>& nums, int start, int end) {
  if (start > end) return -1;
  int mid = start + (end - start) / 2;
  if (isDifferent(nums, mid)) return mid;
  if (isDifferent(nums, start)) return start;
  if (isDifferent(nums, end)) return end;
  if (mid % 2 != 0) mid--;
  if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
    return search(nums, mid, end);
  }
  return search(nums, start, mid);
}

// O (log(nums.size())) time
// O (1) memory
int search2(const vector<int>& nums) {
  int start = 0, end = nums.size() - 1, mid;
  while (start <= end) {
    mid = start + (end - start) / 2;
    if (isDifferent(nums, mid)) return mid;
    if (isDifferent(nums, start)) return start;
    if (isDifferent(nums, end)) return end;
    if (mid % 2 != 0) mid--;
    if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1])
      start = mid;
    else end = mid;
  }
  return -1;
}

int singleNonDuplicate(vector<int>& nums) {
  // int diff_index = search(nums, 0, nums.size() - 1);
  int diff_index = search2(nums);
  return nums[diff_index];
}

int main(void) {
  vector<int> input = {3,3,7,7,11,12,12};
  cout << singleNonDuplicate(input) << endl;
  return 0;
}
