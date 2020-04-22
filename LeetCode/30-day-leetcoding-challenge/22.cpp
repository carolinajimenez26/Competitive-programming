#include <iostream>
#include <vector>
#include <unordered_map>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    // prefix_sum[j] - prefix_sum[i] = k means we have the sum of k between j and i + 1
    // so, prefix_sum[j] - k = prefix_sum[i]
    int result = 0;
    unordered_map<int, int> freqs; // knows all the prefix_sum[i]
    freqs[0] = 1;
    int sum = 0; // same as prefix_sum[j]
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (freqs.count(sum - k) > 0) {
        result += freqs[sum - k];
      }
      freqs[sum]++;
    }
    return result;
  }
};

struct Test {
  vector<int> v;
  int k;
  int out;
};

int main(void) {
  vector<Test> tests = {
    {
      {1,3,2,3,3,2,1},
      8,
      3
    },
    {
      {1,2,3,5,8,7,7,1},
      8,
      3
    },
    {
      {1,1,1},
      2,
      2
    },
    {
      {1,1,1,1},
      2,
      3
    },
    {
      {1,0,0,1,1,1,0,0},
      2,
      7
    },
    {
      {3,0,5,0,0,8},
      8,
      6
    },
    {
      {3,0,5,0,0,8,0,0},
      8,
      12
    },
    {
      {1,3,4,5,0,8,6,0,0,0,7,1,1},
      9,
      6
    },
    {
      {1,3,4,5,0,8,6,0,0,0,7,1,1},
      7,
      5
    },
    {
      {2,5,0,7},
      7,
      4
    },
    {
      {-1,-1,1},
      0,
      1
    }
  };
  bool succeed = true;
  int tc = 0;
  Solution sol;
  for (auto test : tests) {
    int out = sol.subarraySum(test.v, test.k);
    if (out != test.out) {
      cout << "Failed on test #" << tc << ". Expected " << test.out
          << ", found " << out << endl;
      succeed = false;
    }
    tc++;
  }
  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;
  return 0;
}