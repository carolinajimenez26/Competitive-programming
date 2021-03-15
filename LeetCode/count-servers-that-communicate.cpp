#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Position {
  int row, col;
  Position(int row, int col) : row(row), col(col) {}

  bool operator<(const Position& other) const {
    if (row != other.row) {
      return row < other.row;
    }
    return col < other.col;
  }
};

class Solution {
private:
  vector<vector<int>> grid;

  vector<Position> CalculateConnections(Position pos, int delta_row, int delta_col) {
    vector<Position> result;
    while (pos.row < grid.size() && pos.col < grid[0].size()) {
      if (grid[pos.row][pos.col]) {
        result.emplace_back(pos.row, pos.col);
      }
      pos.row += delta_row;
      pos.col += delta_col;
    }
    if (result.size() == 1) {
      return {};
    }
    return result;
  }

  void Insert(const vector<Position>& positions, set<Position>& target) {
    for (auto pos : positions) {
      target.insert(pos);
    }
  }

public:
  int countServers(vector<vector<int>>& grid_) {
    grid = grid_;
    set<Position> result;
    for (int row = 0; row < grid.size(); row++) {
      Position pos = {row, 0};
      vector<Position> connections = CalculateConnections(pos, 0, 1);
      Insert(connections, result);
    }
    for (int col = 0; col < grid[0].size(); col++) {
      Position pos = {0, col};
      vector<Position> connections = CalculateConnections(pos, 1, 0);
      Insert(connections, result);
    }
    return result.size();
  }
};

struct Test {
  vector<vector<int>> grid;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {
        {1,1,0,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,1},
      }, 4
    },
    {
      {
        {1,0,0,1},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,1},
      }, 5
    },
    {
      {
        {1,0,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,1},
      }, 4
    },
    {
      {
        {1,0,1,0},
        {0,0,1,0},
        {0,0,1,1},
        {0,0,0,1},
      }, 6
    },
    {
      {
        {1,0,0,0},
        {0,0,1,0},
        {0,0,0,0},
        {0,0,0,1},
      }, 0
    },
    {
      {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,1},
        {0,0,1,1},
        {0,0,0,1}
      }, 8
    },
    {
      {
        {1,1},
        {0,1},
        {1,0},
      }, 4
    }
  };

  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.countServers(test.grid);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}