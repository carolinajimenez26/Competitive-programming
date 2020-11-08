#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: O(digits.size())
  // Space: O(digits.size())
  vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits;
      } else {
        digits[i] = 0;
      }
    }
    vector<int> ans = {1};
    ans.insert(ans.end(), digits.begin(), digits.end());
    return ans;
  }
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

struct Test {
  vector<int> digits, expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {1,2,3}, {1,2,4}
    },
    {
      {9}, {1,0}
    },
    {
      {9,9}, {1,0,0}
    },
    {
      {1,2,9}, {1,3,0}
    },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.plusOne(test.digits);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      cout << "Found: " << endl;
      Print(out);
      cout << "Expected: " << endl;
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}