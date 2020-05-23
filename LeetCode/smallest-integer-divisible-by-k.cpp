#include <iostream>
using namespace std;

class Solution {
public:
  int smallestRepunitDivByK(int K) {
    if (K == 1) return 1;
    if (K % 2 == 0 || K % 5 == 0) return -1;
    int last_n = 1;
    int size = 1;
    while (last_n != 0) {
      last_n = (last_n * 10 + 1) % K;
      size++;
    }
    return size;
  }
};

int main(void) {
  Solution sol;
  cout << sol.smallestRepunitDivByK(4) << endl;
  return 0;
}