#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> col_ops = {-1, 0, 1}; // left, same or right
  vector<vector<int>> A;
  int inf = numeric_limits<int>::max();
  vector<vector<int>> dp;
public:
  int minFallingPathSum(int row, int col) {
    if (row >= A.size()) return 0;
    if (dp[row][col] != -1) return dp[row][col];
    int smaller = inf;
    for (int j = 0; j < col_ops.size(); j++) {
      int new_col = col + col_ops[j];
      if (new_col >= 0 && new_col < A[0].size()) {
        smaller = min(smaller, A[row][new_col] + minFallingPathSum(row + 1, new_col));
      }
    }
    dp[row][col] = smaller;
    return smaller;
  }

  int minFallingPathSum(vector<vector<int>>& A_) {
    if (A_.size() == 0) return 0;
    A = A_;
    vector<vector<int>> dp_(A_.size(), vector<int>(A_[0].size(), -1));
    dp = dp_;
    int smaller = inf, row = 0;
    for (int col = 0; col < A[0].size(); col++) {
      smaller = min(smaller, A[row][col] + minFallingPathSum(row + 1, col));
    }
    return smaller;
  }
};

int main(void) {
  vector<vector<int>> input = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  Solution sol;
  cout << sol.minFallingPathSum(input) << endl;
  return 0;
}