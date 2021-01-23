#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    if (mat.empty()) {
      return mat;
    }
    int rows = mat.size();
    if (rows == 0) {
      return mat;
    }
    int cols = mat[0].size();
    for (int col = 0; col < cols; col++) {
      SortDiag(mat, 0, col);
    }
    for (int row = 1; row < rows; row++) {
      SortDiag(mat, row, 0);
    }
    return mat;
  }
private:
  void SortDiag(vector<vector<int>>& mat, int row, int col) {
    vector<int> diag = GetDiagonalValues(mat, row, col);
    sort(diag.begin(), diag.end());
    ReplaceDiag(mat, row, col, diag);
  }

  vector<int> GetDiagonalValues(vector<vector<int>>& mat, int row, int col) {
    vector<int> ans;
    while (row < mat.size() && col < mat[0].size()) {
      ans.push_back(mat[row][col]);
      row++;
      col++;
    }
    return ans;
  }

  void ReplaceDiag(vector<vector<int>>& mat, int row, int col, const vector<int>& new_values) {
    int i = 0;
    while (row < mat.size() && col < mat[0].size() && i < new_values.size()) {
      mat[row][col] = new_values[i];
      row++;
      col++;
      i++;
    }
  }
};

int main(void) {
  return 0;
}