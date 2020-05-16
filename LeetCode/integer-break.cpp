#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
  int GetBest(int n, vector<int>& best) {
    if (best[n] != -1) return best[n];
    int max_product = numeric_limits<int>::min();
    for (int i = 1; i <= n / 2; i++) {
      int best_before = i * GetBest(n - i, best);
      max_product = max(max_product, best_before);
    }
    best[n] = max_product;
    return max_product;
  }

public:
  int integerBreak(int n) {
    if (n <= 3) return n - 1; // n is not less than 2
    vector<int> best(n + 1, -1);
    best[0] = 0, best[1] = 1, best[2] = 2, best[3] = 3;
    return GetBest(n, best);
  }
};

int main(void) {
  Solution sol;
  cout << sol.integerBreak(10) << endl;
  return 0;
}