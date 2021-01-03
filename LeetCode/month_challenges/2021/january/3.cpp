#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

class Solution {
public:
  int countArrangement(int n) {
    MAX = n;
    bitset<16> mask;
    mask.reset();
    return HowManyBeautiful(mask);
  }
private:
  int MAX;
  unordered_map<string, int> memo;

  bool IsBeautiful(int a, int b) {
    return (a % b == 0) || (b % a == 0);
  }

  int HowManyBeautiful(bitset<16> mask) {
    if (mask.count() >= MAX) {
      return 1;
    }
    const string mask_string = mask.to_string();
    if (memo.count(mask_string)) {
      return memo[mask_string];
    }
    int ans = 0;
    for (int num = 1; num <= MAX; num++) {
      if (!mask.test(num) && IsBeautiful(num, mask.count() + 1)) {
        mask.set(num);
        ans += HowManyBeautiful(mask);
        mask.reset(num);
      }
    }
    memo[mask_string] = ans;
    return ans;
  }
};

/*
 n = 3 => 1, 2, 3:

 [1] -> [1,2] -> [1,2,3]
        [1,3] -> [1,3,2]
 [2] -> [2,1] -> [2,1,3]
        [2,3] -> [2,3,1]
 [3] -> [3,1] -> [3,1,2]
        [3,2] -> [3,2,1]
*/

struct Test {
  int n;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { 1, 1 },
    { 2, 2 },
    { 3, 3 },
    { 4, 8 },
    { 6, 36 },
    { 15, 24679 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.countArrangement(test.n);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}