#include <iostream>
#include <vector>
using namespace std;
using int64 = long long int;

class Solution {
public:
  int arrangeCoins(int n) {
    if (n == 0) return 0;
    int64 acc = 0;
    for (int i = 1; i <= n; i++) {
      acc += i;
      if (acc >= n) {
        return acc == n ? i : i - 1;
      }
    }
    return -1; //error
  }
};

struct Test {
  int n, ans;
};

int main(void) {
  vector<Test> tests = {
    { 1, 1 },
    { 2, 1 },
    { 3, 2 },
    { 4, 2 },
    { 5, 2 },
    { 6, 3 },
    { 7, 3 },
    { 8, 3 },
    { 9, 3 },
    { 10, 4 },
    { 11, 4 },
    { 12, 4 },
    { 13, 4 },
    { 14, 4 },
    { 15, 5 },
    { 2147483647,  }
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int out = sol.arrangeCoins(test.n);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }

  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}