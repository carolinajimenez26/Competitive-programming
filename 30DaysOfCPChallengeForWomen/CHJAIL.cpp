#include <iostream>
#include <vector>

using namespace std;

struct JailCaracs {
  int rows;
  int cols;
  pair<int,int> drain_pos;

  bool isDrainPos(int row, int col) {
    return row == drain_pos.first && col == drain_pos.second;
  }
};

bool CanEscape(const vector<vector<int>>& jail, JailCaracs& jc, int row, int col, int sum) {
  if (row >= jc.rows || col >= jc.cols) {
    return false;
  }
  sum -= jail[row][col];
  if (sum < 0) {
    return false;
  }
  if (jc.isDrainPos(row, col)) {
    return true;
  }
  if ( CanEscape(jail, jc, row, col + 1, sum) || CanEscape(jail, jc, row + 1, col, sum) ||
      CanEscape(jail, jc, row + 1, col + 1, sum) ) {
    return true;
  }
  return false;
}

bool CanEscape(const vector<vector<int>>& jail, JailCaracs& jc) {
  if (jc.rows == 0 || jc.cols == 0) return false;
  int sum = jail[0][0];
  if ( CanEscape(jail, jc, 0, 1, sum) || CanEscape(jail, jc, 1, 0, sum) ||
      CanEscape(jail, jc, 1, 1, sum) ) {
    return true;
  }
  return false;
}

void print(const vector<vector<int>>& vv, int rows, int cols) {
  for (int row = 0; row < rows; row++) {
      for (int col = 0; col < cols; col++) {
        cout << vv[row][col] << " ";
      }
      cout << endl;
    }
}

int main(void) {
  int tc, M, N, x, y;
  vector<vector<int>> jail(505, vector<int>(505));
  cin >> tc;
  while (tc) {
    cin >> M >> N >> x >> y;
    x--; y--;
    JailCaracs jc{M, N, {x,y}};
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        cin >> jail[i][j];
      }
    }
    // print(jail, M, N);
    bool can_escape = CanEscape(jail, jc);
    if (can_escape || (x == 0 && y == 0)) {
      cout << "Escape" << endl;
    } else {
      cout << "Died" << endl;
    }
    tc--;
  }
  return 0;
}