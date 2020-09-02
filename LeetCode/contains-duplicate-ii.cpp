#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
  // O (nums.size() ^ 2)
  bool containsNearbyDuplicateSlow(vector<int>& nums, int k) {
    if (k == 0 || nums.size() <= 1) return false;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size() && j <= i + k; j++) {
        if (nums[i] == nums[j]) return true;
      }
    }
    return false;
  }

  // O (nums.size())
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if (k == 0 || nums.size() <= 1) return false;
    unordered_map<int, set<int>> numbers_positions;
    for (int i = 0; i < nums.size(); i++) numbers_positions[nums[i]].insert(i);
    for (auto [n, positions] : numbers_positions) {
      auto first = positions.begin();
      auto last = positions.empty() ? positions.end() : prev(positions.end());
      for (auto it = first; it != last; ++it) {
        int pos1 = *it;
        int pos2 = *(next(it));
        if (pos2 - pos1 <= k) return true;
      }
    }
    return false;
  }
};

struct Test {
  vector<int> nums; 
  int k;
  bool ans;
};

int main(void) {
  vector<Test> tests = { // you should define your Test structure
    { {1,2,3,1}, 3, true},
    { {1,0,1,1}, 1,  true },
    { {1,2,3,1,2,3}, 2, false },
    { {}, 2, false },
    { {1}, 1, false },
    { {1,1}, 1, true },
    { {1,1}, 0, false },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.containsNearbyDuplicate(test.nums, test.k);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}