#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
  bool isPowerOfFour(int num) {
    if (num == 1) return true;
    if (num <= 0) return false;
    int zeros = log2(num);
    return (((num & (num - 1)) == 0) && (zeros % 2) == 0);
  }
};

/*
               binary
                 
4^0 = 1       =>         1
4^1 = 4       =>       100
4^2 = 16      =>     10000
4^3 = 64      =>   1000000
4^4 = 256     => 100000000
.
.
.

  16  &  15 = 0
10000 & (01111) = 0

number of zeros = log2(16) = 4
*/

int main(void) {
  return 0;
}