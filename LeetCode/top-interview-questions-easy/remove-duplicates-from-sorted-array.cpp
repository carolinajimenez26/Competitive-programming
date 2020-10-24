#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int findFirstDifferent(const vector<int>& v, int i) {
    int pivot = v[i];
    while (i < v.size() && v[i] == pivot) {
      i++;
    }
    return i;
  }
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty() || nums.size() == 1) return nums.size();
    int writer = 0, available = 0;
    while (available < nums.size()) {
      nums[writer] = nums[available];
      writer++;
      available = findFirstDifferent(nums, available);
    }
    nums.erase(nums.begin() + writer, nums.end());
    return nums.size();
  }
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

struct Test {
  vector<int> nums, expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {},
      {}
    },
    {
      {1},
      {1}
    },
    {
      {1,2,3},
      {1,2,3}
    },
    {
      {1,1,2},
      {1,2}
    },
    {
      {1,2,2},
      {1,2}
    },
    {
      {0,0,1,1,1,2,2,3,3,4},
      {0,1,2,3,4}
    },
  };
  bool succeed = true;
  int tc = 0;
  for (auto test : tests) {
    Solution sol;
    sol.removeDuplicates(test.nums);
    if (test.nums != test.expected) {
      cout << "Failed on test #" << tc << endl;
      cout << "Found: " << endl;
      Print(test.nums);
      cout << "Expected: " << endl;
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good Job" : "Keep trying") << endl;
  return 0;
}