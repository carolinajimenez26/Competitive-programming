#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> visited;
    while (n != 1) {
      int sum = SumOfSquareDigits(n);
      if (sum == 1) return true;
      if (visited.count(sum)) return false;
      visited.insert(sum);
      n = sum;
    }
    return true;
  }
private:
  int SumOfSquareDigits(int n) {
    int res = 0;
    while (n > 0) {
      int x = n % 10;
      res += (x * x);
      n /= 10;
    }
    return res;
  }
};

int main(void) {
  Solution sol;
  cout << sol.isHappy(86) << endl;
  return 0;
}