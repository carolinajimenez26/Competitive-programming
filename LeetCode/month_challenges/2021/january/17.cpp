#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countVowelStrings(int n) {
    max_size = n;
    memo = vector<vector<int>>(n, vector<int>(5, -1));
    int ans = 0;
    for (int i = 0; i < vowels.size(); i++) {
      ans += CountAll(1, i);
    }
    return ans;
  }
private:
  const vector<char> vowels = {'a','e','i','o','u'};
  int max_size;
  vector<vector<int>> memo;

  int CountAll(int curr_size, int last_letter) {
    if (curr_size == max_size) {
      return 1;
    }
    if (memo[curr_size][last_letter] != -1) {
      return memo[curr_size][last_letter];
    }
    int ans = 0;
    for (int i = last_letter; i < vowels.size(); i++) {
      ans += CountAll(curr_size + 1, i);
    }
    memo[curr_size][last_letter] = ans;
    return ans;
  }
};

struct Test {
  int n, expected;
};

int main(void) {
  vector<Test> tests = {
    {1, 5},
    {2, 15},
    {33, 66045}
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.countVowelStrings(test.n);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}