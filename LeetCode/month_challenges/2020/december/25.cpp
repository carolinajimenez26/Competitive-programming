#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix_) {
    if (matrix_.empty()) return {};
    matrix = matrix_;
    rows = matrix.size();
    cols = matrix[0].size();
    int row, col;
    row = col = 0;
    while (row <= rows && col <= cols) {
      DiagonalUp(row, col);
      row++; // down
      DiagonalDown(row, col);
      col++; // right
    }
    return ans;
  }
private:
  vector<int> ans;
  int rows, cols;
  vector<vector<int>> matrix;

  bool IsValid(int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
  }

  void DiagonalUp(int& row, int& col) {
    while (row > -1 && col < cols) {
      if (IsValid(row, col)) ans.push_back(matrix[row][col]);
      row--; col++;
    }
  }

  void DiagonalDown(int& row, int& col) {
    while (row < rows && col > -1) {
      if (IsValid(row, col)) ans.push_back(matrix[row][col]);
      row++; col--;
    }
  }
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

struct Test {
  vector<vector<int>> matrix;
  vector<int> expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {}, 
      {}
    },
    {
      {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
      }, 
      {1,2,4,7,5,3,6,8,9}
    },
    {
      {
        { 1, 2, 3 },
      }, 
      {1,2,3}
    },
    {
      {
        { 1 },
      }, 
      {1}
    },
    {
      {
        {},
      }, 
      {}
    },
    {
      {
        { 1 },
        { 2 }
      }, 
      {1,2}
    },
    {
      {
        { 1, 2 },
        { 3, 4 }
      }, 
      {1,2,3,4}
    },
    {
      {
        { 1, 2, 3 },
        { 4, 5, 6 }
      }, 
      {1,2,4,5,3,6}
    },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.findDiagonalOrder(test.matrix);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      Print(out); 
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}