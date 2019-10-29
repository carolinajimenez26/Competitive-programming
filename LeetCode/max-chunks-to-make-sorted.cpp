#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    int idx = 0;
    int result = 0;
    while (idx < arr.size()) {
      int max = arr[idx];
      while (idx < max) {
        int max_copy = max;
        for (int i = idx; i <= max; i++, idx++) {
          if (max_copy < arr[i]) {
            max_copy = arr[i];
          }
        }
        max = max_copy;
        idx--;
      }
      idx++;
      result++;
    }
    return result;
  }
};

struct Test {
  vector<int> input;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {2,6,1,3,0,5,4},
      1
    },
    {
      {0,4,5,2,1,3},
      2
    },
    {
      {0,4,5,6,2,1,3},
      2
    },
    {
      {4,3,2,1,0},
      1
    },
    {
      {1,0,2,3,4},
      4
    },
    {
      {0,1,2,4,3,7,6,5},
      5
    }
  };
  bool succeed = true;
  int tc = 0;
  for (auto test : tests) {
    Solution sol;
    int out = sol.maxChunksToSorted(test.input);
    if (out != test.expected) {
      succeed = false;
      cout << "Failed on test #" << tc << endl;
      cout << "Got " << out << ", expected " << test.expected << endl; 
    }
    tc++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}