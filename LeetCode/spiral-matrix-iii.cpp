#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

void print(vector<vector<int>> v) {
  for (auto& vi : v) {
    cout << "[";
    for (auto& i : vi) cout << i << ",";
    cout << "]";
  }
  cout << endl;
}

// dir = [right, down, left, up];
const int delta_row[] = {0, 1, 0, -1};
const int delta_col[] = {1, 0, -1, 0};

struct Board {
  int R, C;
  int maxCol, minCol, maxRow, minRow;
  int row, col;
  set<pair<int,int>> visited;
  vector<vector<int>> result;
  int elements_visited;

  Board(int R_, int C_, int row_, int col_) :
    R(R_), C(C_), row(row_), col(col_), minCol(col_ - 1), maxCol(col_ + 1),
    maxRow(row_ + 1), minRow(row_ - 1), elements_visited(0) {}

  void Expand() {
    minRow--;
    minCol--;
    maxRow++;
    maxCol++;
  }

  bool exists(int r_, int c_) {
    return r_ >= 0 && r_ < R && c_ >= 0 && c_ < C;
  }

  void Move(int dir) {
    while (col >= minCol && col <= maxCol && row >= minRow && row <= maxRow) {
      pair<int, int> current_position = make_pair(row, col);
      cout << row << " " << col << endl;
      if (exists(row, col) && visited.count(current_position) == 0) {
        visited.insert(current_position);
        result.push_back({row, col});
        elements_visited++;
      }
      row += delta_row[dir];
      col += delta_col[dir];
    }
    row -= delta_row[dir];
    col -= delta_col[dir];
  }
};

vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
  Board board(R, C, r0, c0);
  while (board.elements_visited < (R * C)) {
    for (int dir = 0; dir < 4; dir++) {
      board.Move(dir);
    }
    board.Expand();
  }
  return board.result;
}

int main(void) {
  int R = 5, C = 6, r0 = 1, c0 = 4;
  // int R = 1, C = 4, r0 = 0, c0 = 0;
  vector<vector<int>> output = spiralMatrixIII(R, C, r0, c0);
  print(output);
  return 0;
}
