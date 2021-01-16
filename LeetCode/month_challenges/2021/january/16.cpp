#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  void Print(const multiset<int>& s) {
    for (auto e : s) cout << e << " ";
    cout << endl;
  }

  int findKthLargest(vector<int>& nums, int k) {
    multiset<int> largests;
    for (int i = 0; i < nums.size(); i++) {
      largests.insert(nums[i]);
      if (largests.size() > k) {
        largests.erase(largests.begin());
      }
    }
    // Print(largests);
    return *largests.begin();
  }
};

struct Test {
  vector<int> nums;
  int k;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,2,2,3,3,4,5,5,6}, 4, 4 },
    { {3,2,1,5,6,4}, 2, 5 },
    { {1,2,3,4,5,5,6}, 3, 5 },
    { {5}, 1, 5 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.findKthLargest(test.nums, test.k);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}