#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define N 4
int board[N]; // index is the column and value is the row

void print() {
  for (int i = 0; i < N; i++) cout << board[i] << " " << endl;
}

bool place(int row, int col) {
  for (int i = 0; i < col; i++) { // we put the queens from left to right
    if (board[i] == row or abs(board[i] - row) == abs(i - col)) return false;
  }
  return true;
}

bool backtrack(int col) {
  dbg(col);
  if (col == N) {
    cout << "Finished!" << endl;
    print();
    return true;
  }
  for (int i = 0; i < N; i++) {
    if (place(i, col)) {
      board[col] = i;
      if (backtrack(col + 1)) return true;
      board[col] = 0;
    }
  }
  return false;
}

int main(void) {
  memset(board, 0, sizeof board);
  backtrack(0);
  return 0;
}
