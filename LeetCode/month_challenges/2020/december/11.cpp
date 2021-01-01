#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int reader = 0, writer = -1;
    while (reader < nums.size()) {
      int curr = nums[reader];
      for (int amount = 0; 
           amount < 2 && reader < nums.size() && nums[reader] == curr; 
           amount++, reader++) {
        
        if (writer != -1) {
          nums[writer] = nums[reader];
          writer++;
        }
      }
      while (reader < nums.size() && nums[reader] == curr) {
        if (writer == -1) {
          writer = reader;
        }
        reader++;
      }
    }
    int ans = nums.size();
    if (writer != -1) ans = nums.size() - (reader - writer);
    return ans;
  }
};

struct Test {
  vector<int> nums;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {0,0,0,1,1,1,2,2,3}, 7 }, 
    { {1,1,1,2,2,3}, 5 },
    { {0,0,1,1,1,1,2,3,3}, 7 },
    { {0,1,1,2,3,3}, 6 },
    { {0,0,0,1,2,3}, 5 },
    { {0,1,2,3}, 4 },
    { {}, 0 },
    { {1}, 1 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.removeDuplicates(test.nums);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " 
           << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}