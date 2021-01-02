#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

struct PrefixSum {
  vector<int> sum;

  PrefixSum(const vector<int>& v) {
    if (v.empty()) return;
    sum.assign(v.size(), 0);
    sum[0] = v[0];
    for (int i = 1; i < v.size(); i++) {
      sum[i] = sum[i - 1] + v[i];
    }
  }

  bool IsValid(int idx) {
    return idx >= 0 && idx < sum.size();
  }

  int Get(int from, int to) {
    if (!IsValid(from) || !IsValid(to) || from > to) {
      assert("Cannot get prefix sum of invalid ranges" && false);
    }
    if (from == 0) {
      return sum[to];
    }
    return sum[to] - sum[from - 1];
  }
};

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    if (nums.empty()) return {};
    PrefixSum prefix_sum(nums);
    // Print(nums);
    // Print(prefix_sum.sum);
    vector<int> ans(nums.size(), 0);
    int last = nums.size() - 1;
    for (int i = 0; i < last; i++) {
      int times_left = nums[i] * (i + 1);
      int times_right = nums[i] * (nums.size() - i - 1);
      int left = times_left - prefix_sum.Get(0, i);
      int right = prefix_sum.Get(i + 1, last) - times_right;
      ans[i] = left + right;
    }
    ans[last] = nums[last] * nums.size() - prefix_sum.Get(0, last);
    return ans;
  }
};

/*
nums = [2,3,5]
prefix_sum = [2,5,10]


i = 0:
5 - 2 + 3 - 2 + 2 - 2
(5 + 3 + 2) - 2*3 = 10 - 6 = 4
[2*1 - (2)] + [(3 + 5) - 2*2] = [0] + [8 - 4] = 4

i = 1:
[3 - 2 + 3 - 3] + [5 - 3]
[3*2 + (-2 - 3)] + [(5) - 3*1]
[3*2 - (2 + 3)] + [5 - 3] = [6 - 5] + [2] = 3

i = 2:
5 - 2 + 5 - 3 + 5 - 5
(-2 - 3 - 5) + 5*3
5*3 - (2 + 3 + 5) = 15 - 10 = 5
*/

struct Test {
  vector<int> nums;
  vector<int> expected;
};

int main(void) {
  vector<Test> tests = {
    { {2,3,5}, {4,3,5} },
    { {1,2,3,5}, {7,5,5,9} },
    { {1,4,6,8,10}, {24,15,13,15,21} },
    { {}, {} },
    { {1}, {0} },
    { {1,2}, {1, 1} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.getSumAbsoluteDifferences(test.nums);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      Print(out);
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}