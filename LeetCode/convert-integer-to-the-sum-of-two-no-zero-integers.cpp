#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  bool ContainsZeros(int N) {
    while (N > 0) {
      int remainder = N % 10;
      if (remainder == 0) return true;
      N /= 10;
    }
    return false;
  }
public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i < n; i++) {
      int x = n - i;
      if (!ContainsZeros(i) && !ContainsZeros(x)) {
        return {i,x};
      }
    }
    return {};
  }
};

int main(void) {
  return 0;
}