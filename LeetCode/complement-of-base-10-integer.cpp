#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
  int bitwiseComplement(int N) {
    int bits_N = log2(N);
    int mask = (1 << bits_N) - 1;
    return ~N & mask;
  }
};

int main(void) {
  return 0;
}