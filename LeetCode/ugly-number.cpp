#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool isUgly(int n) {
    if (n == 0) return false;
    vector<int> primes = {2,3,5};
    for (int i = 0; i < primes.size(); i++) {
      while (n % primes[i] == 0) {
        n /= primes[i];
      }
    }
    if (n == 1) return true;
    return false;
  }
};

/*
55 / 5 = 11 / 11 = 1

50 / 2 = 25 / 5 = 5 / 5 = 1

32 / 2 = 16 / 2 = 8 / 2 = 4 / 2 = 2 / 2 = 1

*/

int main(void) {
  return 0;
}