#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define INF 10000000
#define N 8
int board_in[N]; // index is the column and value is the row
int board[N];

void print() {
  for (int i = 0; i < N; i++) cout << board[i] << " ";
  cout << endl;
}

bool place(int row, int col) {
  for (int i = 0; i < col; i++) { // we put the queens from left to right
    if (board[i] == row or abs(board[i] - row) == abs(i - col)) return false;
  }
  return true;
}

// int backtrack(int col) {
//    if (col == N) {
//      return 0;
//    }
//    int minimum = INF, tmp = INF;
//    for(int i = 0; i < N; i++){
//      if(place(i, col)) {
//        board[col] = i;
//        if (i == board_in[col]) tmp = backtrack(col + 1);
//        else tmp = 1 + backtrack(col + 1);
//        minimum = min(minimum, tmp);
//      }
//    }
//    return minimum;
// }

int backtrack(int col, int moves, int &solution) {
  if (col == N) {
    if (moves < solution) solution = moves;
  }
  for (int i = 0; i < N; i++) {
    if (place(i, col)) {
      board[col] = i;
      moves += (board_in[col] == i ? 0 : 1);
      int tmp = backtrack(col + 1, moves, solution);
      if (tmp != -1) return tmp;
      board[col] = 0;
      moves -= (board_in[col] == i ? 0 : 1);
    }
  }
  return -1;
}

void fill(string &s) {
  stringstream ss;
  ss << s;
  int tok;
  int i = 0;
  while (ss >> tok) {
    board_in[i] = tok - 1;
    i++;
  }
}

int main(void) {
  string line;
  int i = 1, solution;
  while (getline(cin, line)) {
    fill(line);
    // print();
    solution = INF;
    backtrack(0,0, solution);
    cout << "Case " << i << ": " << solution << endl;
    i++;
  }
  return 0;
}
