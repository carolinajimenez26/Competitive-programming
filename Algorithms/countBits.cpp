#include <iostream>

using namespace std;

int CountOnes(int x) {
  int ans = 0;
  while (x > 0) {
    if (x % 2 != 0) ans++;
    x >>= 1;
  }
  return ans;
}

int main(void) {
  cout << CountOnes(5) << endl;
  return 0;
}
