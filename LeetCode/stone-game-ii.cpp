#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
  vector<vector<int>> memo; 
  vector<int> suffix_sum;
public:
  int stoneGameII(const vector<int>& piles, int M, int idx) {
    if (idx >= piles.size()) {
      return 0;
    }
    if (memo[idx][M] != -1) {
      return memo[idx][M];
    }
    int best = 0;
    for (int i = idx, X = 1; i < piles.size() &&  X <= 2 * M; i++, X++) {
      int result = suffix_sum[idx] - stoneGameII(piles, max(M, X), i + 1);
      best = max(best, result);
    }
    memo[idx][M] = best;
    return best;
  }

  int stoneGameII(vector<int>& piles) {
    if (piles.empty()) {
      return 0;
    }
    memo.assign(piles.size(), vector<int>(piles.size() * 2, -1));
    suffix_sum.assign(piles.size(), 0);
    int last = piles.size() - 1;
    suffix_sum[last] = piles[last];
    for (int i = last - 1; i >= 0; i--) {
      suffix_sum[i] = suffix_sum[i + 1] + piles[i];
    }
    // Print(suffix_sum);
    int result = stoneGameII(piles, 1, 0);
    // Print(memo);
    return result;
  }

  void Print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }

  void Print(const vector<vector<int>>& vvi) {
    for (auto vi : vvi) Print(vi);
    cout << endl;
  }
};

int main(void) {
  Solution sol;
  vector<int> input = {2,7,9,4,4};
  cout << sol.stoneGameII(input) << endl;
  return 0;
}
