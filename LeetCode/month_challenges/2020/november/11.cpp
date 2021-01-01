#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  // Runtime: O(rows*cols)
  // Space: O(1)
  void Flip(vector<vector<int>>& A) {
    for (int row = 0; row < A.size(); row++) {
      int col_left = 0, col_right = A[0].size() - 1;
      while (col_left < col_right) {
        int tmp = A[row][col_left];
        A[row][col_left] = A[row][col_right];
        A[row][col_right] = tmp;
        col_left++;
        col_right--;
      }
    }
  }
  // Runtime: O(rows*cols)
  // Space: O(1)
  void Invert(vector<vector<int>>& A) {
    for (int row = 0; row < A.size(); row++) {
      for (int col = 0; col < A[0].size(); col++) {
        A[row][col] = !A[row][col];
      }
    }
  }
public:
  // Runtime: O(rows*cols)
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    Flip(A);
    Invert(A);
    return A;
  }
};

int main(void) {
  return 0;
}