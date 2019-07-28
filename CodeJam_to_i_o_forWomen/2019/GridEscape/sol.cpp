#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

void print(vector<vector<int>> &M, int R, int C) {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << M[i][j];
    }
    cout << endl;
  }
}

void print(vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void move(vector<vector<int>> &board, int& row, int& col) {
  if (board[row][col] == 0) { // North
    row--;
    return;
  }
  if (board[row][col] == 1) { // East
    col++;
    return;
  }
  if (board[row][col] == 2) { // South
    row++;
    return;
  }
  if (board[row][col] == 3) { // Western
    col--;
    return;
  }
}

bool OutOfTheBoard(int R, int C, pair<int,int> pos) {
  if (pos.first < 0) return true;
  if (pos.first >= R) return true;
  if (pos.second < 0) return true;
  if (pos.second >= C) return true;
  return false;
}

bool play(vector<vector<int>> &board, int K) {
  int scaped = 0;
  pair<int, int> player_position;
  set<pair<int,int>> visited;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {

      int row = i, col = j;
      visited.insert(player_position);
      while (true) {
        player_position = make_pair(row, col);
        if (visited.count(player_position)) break;
        move(board, row, col);
        if (OutOfTheBoard(board.size(), board[0].size(), player_position)) {
          scaped++;
          break;
        } else {
          visited.insert(make_pair(row, col));
        }

      }

      if (scaped == K) return true;
    }

  }
  return scaped == K;
}

bool gridEscape(int R, int C, int K, vector<vector<int>> &result) {
  vector<vector<int>> board(R, vector<int>(C));
  vector<int> dirs = {0, 1, 2, 3};
  int index = 0;
  do {
    print(dirs);
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (index >= 4) index = 0;
        board[i][j] = dirs[index];
        index++;
      }
    }
    dbg("---------------");
    print(board, R, C);
    dbg("---------------");
    if(play(board, K)) {
      result = board;
      return true;
    }
  } while ( next_permutation(dirs.begin(), dirs.end()) );
  return false;
}

int main(void) {
  int T, R, C, K, current_case = 1;
  vector<vector<int>> result;
  cin >> T;
  while (T--) {
    cin >> R >> C >> K;
    cout << "Case #" << current_case << ": ";
    result.clear();
    if (gridEscape(R, C, K, result)) {
      cout << "POSSIBLE" << endl;
      print(result, R, C);
    } else cout << "IMPOSSIBLE" << endl;
    current_case++;
  }
  return 0;
}
