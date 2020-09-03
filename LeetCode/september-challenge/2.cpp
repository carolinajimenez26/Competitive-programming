#include <iostream>
#include <vector>
#include <set>
using namespace std;

using int64 = long long int;
class Solution {
public:
  bool containsNearbyAlmostDuplicateSlow(vector<int>& nums, int k, int t) {
    if (k == 0 || nums.size() <= 1) return false;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j <= i + k; j++) {
        if (abs(nums[i] - nums[j]) <= t) return true;
      }
    }
    return false;
  }

  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k == 0 || t < 0 || nums.size() <= 1) return false;
    multiset<int64> s;
    int last_pushed = 0;
    for (int i = 0; i < nums.size() && i <= k; i++) {
      s.insert(nums[i]);
      last_pushed = i;
    }
    for (int i = 0; i < nums.size(); i++) {
      auto it = s.find(nums[i]);
      s.erase(it);
      if (s.empty()) return false;
      // from nums[i] - t to nums[i] + t is a valid range
      int64 a = int64(nums[i]) - t;
      int64 b = int64(nums[i]) + t;
      auto left = s.lower_bound(a);
      auto right = s.upper_bound(b);
      if (left != right) return true;
      if (last_pushed + 1 < nums.size()) {
        s.insert(nums[last_pushed + 1]);
        last_pushed++;
      }
    }
    return false;
  }
};

struct Test {
  vector<int> nums; 
  int k, t;
  bool ans;
};

int main(void) {
  vector<Test> tests = {
    { {1,2,3,1}, 3, 0, true},
    { {1,0,1,1}, 1, 2, true },
    { {1,5,9,1,5,9}, 2, 3, false },
    { {1,2,3,1}, 0, 0, false },
    { {}, 2, 3, false },
    { {1}, 1, 3, false },
    { {1,1}, 1, 1, true },
    { {1,1}, 1, 0, true },
    { {-1,-1}, 1, -1, false },
    { {-3, 3}, 2, 4, false },
    { {2147483647,-2147483647}, 1, 2147483647, false },
    { {-2147483648,-2147483647}, 3, 3, true },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.containsNearbyAlmostDuplicate(test.nums, test.k, test.t);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}