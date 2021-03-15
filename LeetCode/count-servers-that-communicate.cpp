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

  vector<Position> CalculateConnectionsRow(int row) {
    vector<Position> result;
    for (int col = 0; col < grid[0].size(); col++) {
      if (grid[row][col]) {
        result.emplace_back(row, col);
      }
    }
    if (result.size() == 1) {
      return {};
    }
    return result;
  }

  vector<Position> CalculateConnectionsCol(int col) {
    vector<Position> result;
    for (int row = 0; row < grid.size(); row++) {
      if (grid[row][col]) {
        result.emplace_back(row, col);
      }
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
    vector<Position> row_connections;
    for (int row = 0; row < grid.size(); row++) {
      vector<Position> row_connections = CalculateConnectionsRow(row);
      Insert(row_connections, result);
    }
    vector<Position> col_connections;
    for (int col = 0; col < grid[0].size(); col++) {
      vector<Position> col_connections = CalculateConnectionsCol(col);
      Insert(col_connections, result);
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