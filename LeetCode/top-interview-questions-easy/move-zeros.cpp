#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  int FindZeroFrom(int idx, const vector<int>& nums) {
    for (int i = idx; i < int(nums.size()); i++) {
      if (nums[i] == 0) return i;
    }
    return nums.size();
  }
public:
  // Runtime: O(nums.size())
  // Space: O(1)
  void moveZeroes(vector<int>& nums) {
    int writer = FindZeroFrom(0, nums);
    int reader = writer;
    while (reader < nums.size()) {
      while (reader < nums.size() && nums[reader] == 0) reader++;
      if (reader >= nums.size() || writer >= nums.size()) break;
      nums[writer] = nums[reader];
      nums[reader] = 0;
      while (writer < nums.size() && nums[writer] != 0) writer++;
    }
  }
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

struct Test {
  vector<int> digits, expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {2,0,3,0,4,5,6,0}, {2,3,4,5,6,0,0,0}
    },
    {
      {0,0,0,1,2,3}, {1,2,3,0,0,0}
    },
    {
      {1,2,3,0,0,0}, {1,2,3,0,0,0}
    },
    {
      {0,0,0}, {0,0,0}
    },
    {
      {1,2,3}, {1,2,3}
    },
    {
      {0}, {0}
    },
    {
      {}, {}
    },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = test.digits;
    sol.moveZeroes(out);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      cout << "Found: " << endl;
      Print(out);
      cout << "Expected: " << endl;
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}