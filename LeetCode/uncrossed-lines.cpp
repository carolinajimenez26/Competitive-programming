#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> A; 
  vector<int> B;
  vector<vector<int>> memo;

  int Find(const vector<int>& v, int target, int from) {
    for (int i = from; i < v.size(); i++) {
      if (v[i] == target) return i;
    }
    return -1;
  }

  int maxUncrossedLines(int A_idx, int B_idx) {
    if (A_idx == A.size() || B_idx == B.size()) {
      return 0;
    }
    if (memo[A_idx][B_idx] != -1) {
      return memo[A_idx][B_idx];
    }
    int first_equal_idx = Find(B, A[A_idx], B_idx);
    if (first_equal_idx == -1) {
      return maxUncrossedLines(A_idx + 1, B_idx);
    }
    int op1 = 1 + maxUncrossedLines(A_idx + 1, first_equal_idx + 1);
    int op2 = maxUncrossedLines(A_idx + 1, B_idx);
    memo[A_idx][B_idx] = max(op1, op2);
    return memo[A_idx][B_idx];
  }
public:
  int maxUncrossedLines(vector<int>& A_, vector<int>& B_) {
    A = A_;
    B = B_;
    memo.assign(A_.size(), vector<int>(B_.size(), -1));
    return maxUncrossedLines(0, 0);
  }
};

int main(void) {
  vector<int> A = {1,4,2}, B = {1,2,4};
  Solution sol;
  cout << sol.maxUncrossedLines(A, B) << endl;
  return 0;
}