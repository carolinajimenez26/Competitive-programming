#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    if (arr.empty()) {
      return k;
    }
    int missing = 0;
    int n = 1;
    for (int i = 0; i < arr.size() && missing < k;) {
      if (arr[i] == n) {
        i++;
      } else {
        missing++;
      }
      n++;
    }
    if (missing == k) {
      return n - 1;
    }
    return arr.back() + k - missing;
  }
};

struct Test {
  vector<int> arr;
  int k;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {2,3,4,7,11}, 5, 9 },
    { {2,3,4,7,11}, 10, 15 },
    { {1,2,3,4}, 2, 6 },
    { {}, 3, 3 },
    { {}, 1, 1 },
    { {1,2,3}, 100, 103 },
    { {1,5,10}, 100, 103 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.findKthPositive(test.arr, test.k);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}