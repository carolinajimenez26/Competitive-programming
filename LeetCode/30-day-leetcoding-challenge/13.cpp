#include <iostream>
#include <vector>
#include <unordered_map>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1) {
      return 0;
    }
    vector<int> psum = PrefixSum(nums);
    // print(psum);
    unordered_map<int, int> seen;
    int best = 0;
    for (int i = 0; i < psum.size(); i++) {
      if (seen.count(psum[i]) == 0) {
        seen[psum[i]] = i;
      }
      best = max(best, i - seen[psum[i]]);
    }
    return best;
  }
private:
  void MoveUntill(int& idx, vector<int>& v, int x) {
    while (idx < v.size()) {
      if (v[idx] == x) {
        break;
      }
      idx++;
    }
  }
  vector<int> PrefixSum(const vector<int>& nums) {
    vector<int> result(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); i++) {
      if (nums[i - 1] == 0) {
        result[i] = result[i - 1] - 1;
      } else {
        result[i] = result[i - 1] + 1;
      }
    }
    return result;
  }
  void print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }
};

struct Test {
  vector<int> nums;
  int best;
};

int main(void) {
  vector<Test> tests = {
    {
      {0,0,0,1,1,0,0,0,1,1,1,0,0},
      10
    },
    {
      {0,0,0,1,1,0,0,0,1,1,0,0},
      8
    },
    {
      {1,1,0,0,1,1,1,0,0},
      8
    },
    {
      {0,0,0,0,0,0,1,1,1,0,0},
      6
    },
    {
      {0},
      0
    },
    {
      {1},
      0
    },
    {
      {0,0},
      0
    },
    {
      {1,1,1,1,1},
      0
    },
    {
      {0,1},
      2
    },
    {
      {1,0,1,0},
      4
    },
    {
      {0,1,1,0,1,1,0},
      4
    },
    {
      {0,1,1,0,1,1,0,0},
      8
    }
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int best = sol.findMaxLength(test.nums);
    if (best != test.best) {
      succeed = false;
      cout << "Failed on test #" << tc << ". Expected " << test.best << ", found "
           << best << endl;
    }
    tc++;
  }
  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;
  return 0;
}