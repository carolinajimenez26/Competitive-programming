#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct Range {
  int left, right;

  int GetSize() {
    if (left == -1) {
      return -1;
    }
    return right - left + 1;
  }

  void Print() {
    cout << "{" << left << "," << right << "}" << endl;
  }
};

class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    if (nums.empty()) {
      return -1;
    }
    if (x == 0) {
      return 0;
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum == x) {
      return nums.size();
    }
    int y = sum - x;
    Range r = GetMaxSubArraySum(nums, y);
    // r.Print();
    if (r.left == -1) {
      return -1;
    }
    return nums.size() - r.GetSize();
  }
private:
  Range GetMaxSubArraySum(const vector<int>& nums, int x) {
    Range greater = {-1,-1};
    if (nums.empty() || x == 0) {
      return greater;
    }
    int left = 0, right = 1;
    int sum = nums[left];
    while (left <= right && right < nums.size()) {
      while (right < nums.size() && sum < x) {
        sum += nums[right];
        right++;
      }
      Range range = {left, right - 1};
      if (sum == x && greater.GetSize() < range.GetSize()) {
        greater = range;
      }
      sum -= nums[left];
      left++;
    }
    Range range = {left, right - 1};
    if (sum == x && greater.GetSize() < range.GetSize()) {
      greater = range;
    }
    return greater;
  }
};

struct Test {
  vector<int> nums;
  int x;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,2,3,4,1,1,1,1}, 6, 3 },
    { {}, 10, -1 },
    { {1,2,3}, 0, 0 },
    { {1,2,3}, 10, -1 },
    { {1,1,4,2,3}, 5, 2 },
    { {5,6,7,8,9}, 4, -1 },
    { {3,2,20,1,1,3}, 10, 5 },
    { {1,2,3,4,5,6}, 21, 6 },
    { {1,2,3,4,5,6}, 1, 1 },
    { {1,2,3,4,5,6}, 7, 2 },
    { {500,1,4,2,3}, 500, 1 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.minOperations(test.nums, test.x);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}