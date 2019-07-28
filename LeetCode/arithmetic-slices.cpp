#include <iostream>
#include <vector>

using namespace std;

int memo[5234][5234];

bool isArithmetic(const vector<int>& A, int start, int end) {
  if (end >= A.size()) return false;
  if (end - 1 == start) return true;
  if (memo[start][end] == -1) {
    memo[start][end] = start + 2 < A.size() &&
                       A[start] - A[start + 1] == A[start + 1] - A[start + 2] &&
                       isArithmetic(A, start + 1, end);
  }
  return memo[start][end];
}

int numberOfArithmeticSlices(vector<int>& A) {
  int result = 0;
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < A.size(); i++) {
    for (int j = i + 2; j < A.size(); j++) {
      if (isArithmetic(A, i, j)) result++;
    }
  }
  return result;
}

int main(void) {
  vector<int> input = {5,6,7,8,9,0};
  cout << numberOfArithmeticSlices(input) << endl;
  return 0;
}
