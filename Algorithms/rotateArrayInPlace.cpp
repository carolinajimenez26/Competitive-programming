// Try it out here:
// https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/646/
#include <iostream>
#include <vector>

using namespace std;

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

class Solution {
public:
  // Space time: O(1)
  // Runtime: O(nums.size())
  void rotate(vector<int>& nums, int times) {
    if (nums.empty() || nums.size() == 1) return;
    times = times % nums.size();
    int moved = 0, initial_idx = 0; 
    while (moved < nums.size()) {
      int to_move = nums[initial_idx];
      int curr_idx = initial_idx + times;
      while (curr_idx != initial_idx) {
        int tmp = nums[curr_idx];
        nums[curr_idx] = to_move;
        to_move = tmp;
        moved++;
        curr_idx = (curr_idx + times) % nums.size();
      }
      nums[initial_idx] = to_move;
      moved++;
      initial_idx++;
    }
  }
  // Space time: O(1)
  // Runtime: O(k * nums.size())
  void rotateSlow(vector<int>& nums, int k) {
    if (nums.empty() || nums.size() == 1) return;
    k = k % nums.size();
    for (int rotation = 0; rotation < k; rotation++) {
      int tmp1, tmp2;
      tmp1 = nums[0]; 
      for (int i = 1; i < nums.size(); i++) {
        tmp2 = nums[i];
        nums[i] = tmp1;
        tmp1 = tmp2;
      }
      nums[0] = tmp1;
    }
  }
};

struct Test {
  vector<int> nums;
  int k;
  vector<int> expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {1},
      3,  
      {1}
    },
    {
      {},
      3,  
      {}
    },
    {
      {1,2},
      3,  
      {2,1}
    },
    {
      {1,2,3},
      3,
      {1,2,3}
    },
    {
      {1,2,3,4,5,6,7},
      3,  
      {5,6,7,1,2,3,4}
    },
    {
      {1,2,3,4},
      2,
      {3,4,1,2}
    },
    {
      {-1,-100,3,99},
      2,
      {3,99,-1,-100}
    },
    {
      {1,2,3,4},
      2,
      {3,4,1,2}
    },
    {
      {1,2,3,4,5,6},
      2,
      {5,6,1,2,3,4}
    }
  };
  bool succeed = true;
  int tc = 0;
  for (auto test : tests) {
    Solution sol;
    sol.rotate(test.nums, test.k);
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