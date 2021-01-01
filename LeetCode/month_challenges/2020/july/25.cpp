#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right + 1) / 2;
      if (nums[left] < nums[right]) {
        return nums[left]; // there is no rotation at all
      }
      if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) { // found breaking point
        return nums[mid];
      }
      if (nums[mid] == nums[left]) {
        left++;
      } else if (nums[mid] > nums[left]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};

struct Test {
  vector<int> nums;
  int ans;
};

int main(void) {
  vector<Test> tests = {
    { {3,4,5,6,7,1,2}, 1 },
    { {1,2,3,4,5,6,7,8,9,10}, 1 },
    { {8,9,10,1,2,3,4,5,6,7}, 1 },
    { {5,6,7,8,9,10,1,2,3,4}, 1 },
    { {1,2}, 1 },
    { {2,1}, 1 },
    { {1}, 1 },
    { {1,2,3}, 1 },
    { {3,1,2}, 1 },
    { {1,3,5}, 1 },
    { {2,2,2,0,1}, 0 },
    { {1,1,1,2,3,4,4,4,5,5,6,7,8,9,10,10,10}, 1 },
    { {10,1,10,10,10}, 1 }
  };

  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int out = sol.findMin(test.nums);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}
