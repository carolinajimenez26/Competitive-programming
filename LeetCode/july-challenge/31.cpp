#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> memo;

  int climbStairsHelper(int n) {
    if (memo[n] != -1) return memo[n];
    if (n < 0) return 0;
    if (n <= 2) return memo[n] = n;
    memo[n] = climbStairsHelper(n - 1) + climbStairsHelper(n - 2);
    return memo[n];
  }

public:
  int climbStairs(int n) {
    memo.resize(n + 1, -1);
    climbStairsHelper(n);
    return memo[n];
  }
};

struct Test {
  int n;
  int ans;
};

int main(void) {
  vector<Test> tests = {
    { 0, 0 },
    { 1, 1 },
    { 2, 2 },
    { 3, 3 },
    { 4, 5 },
    { 5, 8 },
    { 45, 1836311903 },
  };

  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int out = sol.climbStairs(test.n);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}