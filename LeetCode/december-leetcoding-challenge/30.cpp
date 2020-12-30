#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int>>& ans) {
    board = ans;
    for (int row = 0; row < board.size(); row++) {
      for (int col = 0; col < board[0].size(); col++) {
        ans[row][col] = GetValue(row, col);
      }
    }
  }
private:
  vector<vector<int>> board;

  bool IsValid(int row, int col) {
    return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
  }

  int GetValueGivenNeighs(int neighs, bool live_cell) {
    if (!live_cell) {
      if (neighs == 3) return 1;
      return 0;
    }
    if (neighs < 2 || neighs > 3) return 0;
    return 1;
  }

  int GetValue(int row, int col) {
    vector<int> delta_row = {-1, -1, 0, 1, 1,  1,  0, -1};
    vector<int> delta_col = { 0,  1, 1, 1, 0, -1, -1, -1};
    int neighs = 0;
    for (int i = 0; i < delta_row.size(); i++) {
      int new_row = row + delta_row[i];
      int new_col = col + delta_col[i];
      if (IsValid(new_row, new_col) && board[new_row][new_col]) {
        neighs++;
      }
    }
    return GetValueGivenNeighs(neighs, board[row][col]);
  }
};

void Print(const vector<vector<int>>& board) {
  cout << "----" << endl;
  for (int row = 0; row < board.size(); row++) {
    for (int col = 0; col < board[0].size(); col++) {
      cout << board[row][col] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  vector<vector<int>> board = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
  Print(board);
  Solution sol;
  sol.gameOfLife(board);
  Print(board);
  return 0;
}