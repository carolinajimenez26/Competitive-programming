// Cumulative Frequency Array: For Range Sum Queries
#include <iostream>
#include <vector>
using namespace std;
const int rows = 3, cols = 3;

void Print(vector<vector<int>>& M) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int CalcPrefix(int row, int col, const vector<vector<int>>& M) {
  int up = row - 1 >= 0 ? M[row - 1][col] : 0;
  int left = col - 1 >= 0 ? M[row][col - 1] : 0;
  int diag = row - 1 >= 0 && col - 1 >= 0 ? M[row - 1][col - 1] : 0;
  return up + left - diag;
}

vector<vector<int>> CreateCF2D(const vector<vector<int>>& M) {
  vector<vector<int>> result = M;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] += CalcPrefix(i, j, result);
    }
  }
  return result;
}

int QueryPrefix(const vector<vector<int>>& M, pair<int, int> from, pair<int, int> to) {
  int i1 = from.first, j1 = from.second, i2 = to.first, j2 = to.second;
  int rect_up = i1 - 1 >= 0 ? M[i1 - 1][j2] : 0;
  int rect_left = j1 - 1 >= 0 ? M[i2][j1 - 1] : 0;
  int rect_diag = i1 - 1 >= 0 && j1 - 1 >= 0 ? M[i1 - 1][j1 - 1] : 0;
  return M[i2][j2] - rect_up - rect_left + rect_diag;
}

int main(void) {
  vector<vector<int>> M = {
    {1, 2, 3,}, 
    {4, 5, 6,}, 
    {7, 8, 9,},
  };
  Print(M);
  vector<vector<int>> CFM_expected = {
    {1, 3,6},
    {5,12,21},
    {12,27,45},
  };
  vector<vector<int>> CFM = CreateCF2D(M);
  Print(CFM);
  if (CFM != CFM_expected) {
    cout << "Error creating prefix sum 2D" << endl;
    return 0;
  }

  if (QueryPrefix(CFM, {1, 1}, {2, 2}) != 28) {
    cout << "Error querying prefix sum 2D" << endl;
    return 0;
  }

  if (QueryPrefix(CFM, {0, 0}, {2, 2}) != 45) {
    cout << "Error querying prefix sum 2D" << endl;
    return 0;
  }

  if (QueryPrefix(CFM, {1, 0}, {2, 2}) != 39) {
    cout << "Error querying prefix sum 2D" << endl;
    return 0;
  }

  cout << "Good job" << endl;
  return 0;
}
