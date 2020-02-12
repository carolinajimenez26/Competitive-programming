#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
  int GetContinuousSum(const vector<int>& nums, int from, int k) {
    int sum = 0, result = 0;
    sum += nums[from];
    for (int i = from + 1; i < nums.size(); i++) {
      sum += nums[i];
      if (sum == k) {
        result++;
      }
    }
    return result;
  }
  int getCountElementsEquals(const vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == k) {
        sum++;
      }
    }
    return sum;
  }
public:
  // O (n ** 2), where n = nums.size()
  int subarraySum2(vector<int>& nums, int k) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      result += GetContinuousSum(nums, i, k);
    }
    return result + getCountElementsEquals(nums, k);
  }
  // O (n)
  int subarraySum(vector<int>& nums, int k) {
    int count = 0, sum = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        count += m[sum - k];
        m[sum] += 1;
    }
    return count;
  }
};

struct Test {
  vector<int> nums;
  int k;
  int result;
};

int main(void) {
  vector<Test> tests = {
    {
      {1,1,1},
      2,
      2
    },
    {
      {0,0,1,1,0,0,1},
      2,
      10 // {0,3}, {0,4}, {0,5}, {1,3}, {1,4}, {1,5}, {2,3}, {2,4}, {2,5}, {3,6}
    },
    {
      {1,-1,1},
      1,
      3
    },
    {
      {1,-1,1,1},
      1,
      5
    }
  };
  int tc = 0;
  bool succeed = true;

  for (auto test : tests) {
    Solution sol;
    int out = sol.subarraySum(test.nums, test.k);
    if (out != test.result) {
      succeed = false;
      cout << "Failed on test #" << tc << endl;
      cout << "Got " << out << ", expected " << test.result << endl;
    }
    tc++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}