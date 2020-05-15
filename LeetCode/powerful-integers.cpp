#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    set<int> ans;
    for (int i = 1; i <= bound; i *= x) {
      for (int j = 1; j <= bound; j *= y) {
        int z = i + j;
        if (z > bound) {
          break;
        }
        ans.insert(z);
        if (y == 1) break;
      }
      if (x == 1) break;
    }
    return {ans.begin(),ans.end()};
  }
};

int main(void) {
  Solution sol;
  vector<int> out = sol.powerfulIntegers(1,2,10);
  [](const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }(out);
  return 0;
}