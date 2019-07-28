#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define N 8
int board_score[N][N];
int board[N];
map<int, int> sol;

void print() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board_score[i][j] << " ";
    }
    cout << endl;
  }
}

void printsol() {
  for (int i = 0; i < N; i++) cout << board[i] << " ";
  cout << endl;
}

bool place(int row, int col) {
  for (int i = 0; i < col; i++) { // we put the queens from left to right
    if (board[i] == row or abs(board[i] - row) == abs(i - col)) return false;
  }
  return true;
}

int backtrack(int col, int score) {
  if (col == N) {
    sol[score] = 1;
  }
  for (int i = 0; i < N; i++) {
    if (place(i, col)) {
      board[col] = i;
      score += board_score[i][col];
      int tmp = backtrack(col + 1, score);
      if (tmp != -1) return tmp;
      board[col] = 0;
      score -= board_score[i][col];
    }
  }
  return -1;
}

int main(void) {
  int k = 0, score;
  cin >> k; // number of boards
  while (k--) {
    score = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> board_score[i][j];
      }
    }
    backtrack(0, score);
    printf("%5d\n", sol.rbegin()->first);
    sol.clear();
  }
  return 0;
}
