#include <iostream>
#include <vector>
using namespace std;

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

class Solution {
public:
  int getMaximumGenerated(int n) {
    if (n <= 1) {
      return n;
    }
    vector<int> v(n + 1, 0);
    v[1] = 1;
    for (int i = 2; i <= n; i++) {
      int half = i / 2;
      if (i % 2 == 0) {
        v[i] = v[half];
      } else {
        v[i] = v[half] + v[half + 1];
      }
    }
    // Print(v);
    return *max_element(v.begin(), v.end());
  }
};

int main(void) {
  Solution sol;
  cout << sol.getMaximumGenerated(7) << endl;
  return 0;
}