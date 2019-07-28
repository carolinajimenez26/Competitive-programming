#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num) {
  vector<int> ans(num + 1);
  if (num == 0) return ans;
  ans[1] = 1;
  for (int i = 2; i < num + 1; i++) {
    if ((i % 2) == 0) { // even
      ans[i] = ans[i / 2];
    } else {
      ans[i] = ans[i - 1] + 1;
    }
  }
  return ans;
}

int main(void) {
  countBits(5);
  return 0;
}
