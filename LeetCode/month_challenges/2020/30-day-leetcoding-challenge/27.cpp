#include <iostream>
#include <vector>
using namespace std;

struct Cell {
  int row, col;
};

class Solution {
private:
  vector<vector<int>> prefix_sum;

  void print() {
    for (auto v : prefix_sum) {
      for (auto i : v) cout << i << " ";
      cout << endl;
    }
    cout << endl;
  }

  int ToInt(char c) {
    return c - '0';
  }

  void CalculatePrefixSum(const vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    prefix_sum.assign(rows + 1, vector<int>(cols + 1, 0));
    for (int row = 1; row <= rows; row++) {
      for (int col = 1; col <= cols; col++) {
        prefix_sum[row][col] = prefix_sum[row - 1][col] + prefix_sum[row][col - 1]
                               - prefix_sum[row - 1][col - 1] + ToInt(matrix[row - 1][col - 1]);
      }
    }
  }

  bool IsValid(Cell cell) {
    return cell.row >= 0 && cell.row < prefix_sum.size() && cell.col >= 0 &&
           prefix_sum.size() > 0 && cell.col < prefix_sum[0].size();
  }

  int GetSum(Cell from, Cell to) {
    from.row++; from.col++;
    to.row++; to.col++;
    if (!IsValid(from) || !IsValid(to)) {
      return 0;
    }
    return prefix_sum[to.row][to.col] - prefix_sum[from.row - 1][to.col] -
           prefix_sum[to.row][from.col - 1] + prefix_sum[from.row - 1][from.col - 1];
  }
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return 0;
    }
    int rows = matrix.size(), cols = matrix[0].size();
    CalculatePrefixSum(matrix);
    // print();
    int max_square_size = min(rows, cols);
    int best = 0;
    for (int square_size = 0; square_size < max_square_size; square_size++) {
      for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
          Cell from{row, col}, to{row + square_size, col + square_size};
          int sum = GetSum(from, to);
          if (sum == (square_size + 1) * (square_size + 1)) { // all 1's
            best = max(best, sum);
          }
        }
      }
    }
    return best;
  }
};

struct Test {
  vector<vector<char>> matrix;
  int max_sum;
};

int main(void) {
  vector<Test> tests = {
    {
      {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','1','1','1'}
      },
      9
    },
    {
      {{'1','0','1','0','0'},
      {'1','0','1','1','1'},
      {'1','1','1','1','1'},
      {'1','0','0','1','1'}},
      4
    },
    {
      {{'1','1','1'},
      {'0', '0','1'},},
      1
    },
    {
      {{'1','1','1'},
      {'0', '1','1'},},
      4
    },
    {
      {{'0','0','0'},
      {'0', '0','0'},},
      0
    },
    {
      {},
      0
    }
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test: tests) {
    int out = sol.maximalSquare(test.matrix);
    if (out != test.max_sum) {
      cout << "Failed on test #" << tc << ". Expected " << test.max_sum
           << ", found " << out << endl;
      succeed = false;
    }
    tc++;
  }
  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;
  return 0;
}