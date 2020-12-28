#include <iostream>
#include <vector>
using namespace std;
using int64 = long long int;

class Solution {
public:
  int reachNumber(int target) {
    target = abs(target);
    int64 steps = BinarySearch(target);
    if ((GaussSum(steps) - target) % 2 == 0) return steps;
    if ((GaussSum(steps + 1) - target) % 2 == 0) return steps + 1;
    return steps + 2;
  } 
private:
  const int64 MAX = 10e5;

  int64 GaussSum(int64 x) {
    return (x * (x + 1)) / 2;
  }

  int64 BinarySearch(int target) {
    int64 left = 0, right = MAX;
    while (left < right) {
      int64 mid = (left + right) / 2;
      int64 x = GaussSum(mid);
      if (x < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};

struct Test {
  int target;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { 0, 0 },
    { 1, 1 },
    { 3, 2 },
    { -3, 2 },
    { 6, 3 },
    { 50, 11 },
    { -50, 11 },
    { 1000000000, 44723 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.reachNumber(test.target);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}