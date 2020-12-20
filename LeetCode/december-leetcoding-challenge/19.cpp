#include <iostream>
#include <vector>
#include <limits>
#include <cassert>
using namespace std;
#define assertm(exp, msg) assert(((void)msg, exp))

const int INF = numeric_limits<int>::max();

struct Pos {
  int row, col;

  bool operator == (const Pos& other) const {
    return (row == other.row && col == other.col);
  }
};

struct Grid {
  vector<vector<int>> table;

  Grid () {}

  void Set(vector<vector<int>> _table) {
    table.assign(_table.size(), vector<int>(_table[0].size()));
    for (int row = 0; row < _table.size(); row++) {
      for (int col = 0; col < _table[0].size(); col++) {
        table[row][col] = _table[row][col];
      }
    }
  }

  bool IsValid(Pos pos) {
    return pos.row >= 0 && pos.row < table.size() && 
           pos.col >= 0 && pos.col < table[0].size();
  }

  int Get(Pos pos) {
    assertm(IsValid(pos), "pos must be valid");
    return table[pos.row][pos.col];
  }

  void Set(Pos pos, int val) {
    if (!IsValid(pos)) return;
    table[pos.row][pos.col] = val;
  }

  bool IsInLastRow(Pos pos) {
    return pos.row == table.size() - 1;
  }

  int GetRows() {
    return table.size();
  }

  int GetCols() {
    return table[0].size();
  }

  void Print() {
    for (int row = 0; row < table.size(); row++) {
      for (int col = 0; col < table[0].size(); col++) {
        cout << table[row][col] << " ";
      }
      cout << endl;
    }
  }
};

class Solution {
public:
  int cherryPickup(vector<vector<int>>& grid_) {
    if (grid_.empty()) return 0;
    grid.Set(grid_);
    
    memo.assign(grid.GetRows(), vector<vector<int>>
                (grid.GetCols(), vector<int>
                (grid.GetCols(), -1)));
    return GetBest({0,0}, {0, grid.GetCols() - 1});
  }
private:
  Grid grid;
  const vector<int> delta_col = {-1, 0, 1};
  vector<vector<vector<int>>> memo;

  int GetBest(Pos robot1, Pos robot2) {
    assert(robot1.row == robot2.row);
    if (grid.IsInLastRow(robot1)) {
      if (robot1 == robot2) {
        return grid.Get(robot1);
      }
      return grid.Get(robot1) + grid.Get(robot2);
    }

    if (memo[robot1.row][robot1.col][robot2.col] != -1) {
      return memo[robot1.row][robot1.col][robot2.col];
    }

    int cur_sum = grid.Get(robot1) + grid.Get(robot2);
    if (robot1 == robot2) {
      cur_sum /= 2;
    }
    int best = cur_sum;
    for (int i = 0; i < delta_col.size(); i++) { // r1
      Pos new_pos_r1 = {robot1.row + 1, robot1.col + delta_col[i]};
      if (!grid.IsValid(new_pos_r1)) continue;

      for (int j = 0; j < delta_col.size(); j++) { // r2
        Pos new_pos_r2 = {robot2.row + 1, robot2.col + delta_col[j]};
        if (!grid.IsValid(new_pos_r2)) continue;

        int op = cur_sum + GetBest(new_pos_r1, new_pos_r2);
        best = max(best, op);
      }
    }
    memo[robot1.row][robot1.col][robot2.col] = best;
    return best;
  }
};

struct Test {
  vector<vector<int>> grid;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {{3,1,1},{2,5,1},{1,5,5},{2,1,1}}, 24 },
    { {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}}, 28 },
    { {{1,0,0,3},{0,0,0,3},{0,0,3,3},{9,0,3,3}}, 22 },
    { {{1,1},{1,1}}, 4 },
    { {{1,8,7,5},{0,3,0,1},{3,7,9,7},{1,5,3,5}}, 36 }
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.cherryPickup(test.grid);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out 
           << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}