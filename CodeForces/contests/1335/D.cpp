#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

int GetBetween(const unordered_set<int>& unused, int from, int to) {
  for (auto e : unused) {
    if (e >= from && e <= to) {
      return e;
    }
  }
  assert(false);
  return -1;
}

void AntiSudoku(vector<vector<int>>& Sudoku) {
  unordered_set<int> unused_rows, unused_cols;
  for (int i = 0; i < 9; i++) {
    unused_rows.insert(i);
    unused_cols.insert(i);
  }
  for (int i = 0; i < 3; i++) { // square
    for (int j = 0; j < 3; j++) { // square
      int row = GetBetween(unused_rows, i * 3, ((i + 1) * 3) - 1);
      int col = GetBetween(unused_cols, j * 3, ((j + 1) * 3) - 1);
      int n = (Sudoku[row][col] == 9 ? 1 : Sudoku[row][col] + 1);
      Sudoku[row][col] = n;
      unused_rows.erase(row);
      unused_cols.erase(col);
    }
  }
}

void Print(const vector<vector<int>>& Sudoku) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << Sudoku[i][j];
    }
    cout << endl;
  }
}

int main(void) {
  int tc;
  vector<vector<int>> Sudoku(9, vector<int>(9));
  string line;
  cin >> tc;
  while (tc--) {
    for (int i = 0; i < 9; i++) {
      cin >> line;
      for (int j = 0; j < 9; j++) {
        Sudoku[i][j] = (line[j] - '0');
      }
    }
    // Print(Sudoku);
    AntiSudoku(Sudoku);
    Print(Sudoku);
  }
  return 0;
}