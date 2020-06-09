#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

void Print(const vector<vector<bool>>& table) {
  int rows = table.size(), cols = table[0].size();
  cout << "==========" << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  cout << "==========" << endl;
}

struct Player {
  string name;
  bool turn;

  bool operator==(const Player& other) const {
    return name == other.name;
  }
};

void ToggleTurns(Player& p1, Player& p2) {
  p1.turn = !p1.turn;
  p2.turn = !p2.turn;
}

void MarkRow(vector<vector<bool>>& M, int row, int col, bool b) {
  int rows = M.size(), cols = M[0].size();
  for (int i = 0; i < cols; i++) {
    M[row][i] = b;
  }
}

void MarkCol(vector<vector<bool>>& M, int row, int col, bool b) {
  int rows = M.size(), cols = M[0].size();
  for (int i = 0; i < rows; i++) {
    M[i][col] = b;
  }
}

Player Play(Player& p1, Player& p2, vector<vector<bool>>& table) {
  Player curr = p1.turn ? p1 : p2;
  int rows = table.size(), cols = table[0].size();
  bool played = false;

  for (int i = 0; i < rows && !played; i++) {
    for (int j = 0; j < cols && !played; j++) {
      if (table[i][j] == false) {
        MarkRow(table, i, j, true);
        MarkCol(table, i, j, true);
        ToggleTurns(p1,p2);
        played = true;
      }
    }
  }
  if (!played) {
    return curr == p1 ? p2 : p1;
  }
  return Play(p1, p2, table);
}

vector<vector<bool>> MarkTable(vector<vector<bool>>& M) {
  int rows = M.size(), cols = M[0].size();
  vector<vector<bool>> result(rows, vector<bool>(cols));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (M[i][j]) {
        MarkRow(result, i, j, true);
        MarkCol(result, i, j, true);
      }
    }
  }
  return result;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<bool>> M(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int cell;
        cin >> cell;
        M[i][j] = cell;
      }
    }
    M = MarkTable(M);
    // Print(M);
    Player p1{"Ashish", true};
    Player p2{"Vivek", false};
    Player winner = Play(p1, p2, M);
    cout << winner.name << endl;
  }
  return 0;
}