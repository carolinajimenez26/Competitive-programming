#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> memo;
public:
  int longestCommonSubsequence(const string& text1, const string& text2, int idx1, int idx2) {
    if (idx1 >= text1.size() || idx2 >= text2.size()) {
      return 0;
    }
    if (memo[idx1][idx2] != -1) {
      return memo[idx1][idx2];
    }
    int result = 0;
    if (text1[idx1] == text2[idx2]) { // match
      result = 1 + longestCommonSubsequence(text1, text2, idx1 + 1, idx2 + 1);
    } else {
      int op1 = longestCommonSubsequence(text1, text2, idx1 + 1, idx2);
      int op2 = longestCommonSubsequence(text1, text2, idx1, idx2 + 1);
      result = max(op1, op2);
    }
    memo[idx1][idx2] = result;
    return result;
  }

  int longestCommonSubsequence(string text1, string text2) {
    memo.assign(text1.size(), vector<int>(text2.size(), -1));
    return longestCommonSubsequence(text1, text2, 0, 0);
  }
};

int main(void) {
  Solution sol;
  string text1 = "abcde", text2 = "ace";
  cout << sol.longestCommonSubsequence(text1, text2) << endl;
  return 0;
}