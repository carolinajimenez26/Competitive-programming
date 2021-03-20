#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Element {
  int row, col, distance;

  Element(int row, int col, int distance) : row(row), col(col), distance(distance) {}
};

class Solution {
private:
  vector<int> delta_row = {-1,-1,0,1,1, 1, 0,-1};
  vector<int> delta_col = { 0, 1,1,1,0,-1,-1,-1};

  bool IsValid(int row, int col, const vector<vector<int>>& grid) {
    return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()
           && grid[row][col] == 0;
  }
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int last_row = grid.size() - 1;
    int last_col = grid[0].size() - 1;
    queue<Element> pq;
    pq.emplace(0,0,1);
    while (!pq.empty()) {
      Element curr = pq.front();
      pq.pop();
      if (grid[curr.row][curr.col] == 1) {
        continue;
      }
      if (curr.row == last_row && curr.col == last_col) {
        return curr.distance;
      }
      for (int i = 0; i < delta_row.size(); i++) {
        Element next = {curr.row + delta_row[i], curr.col + delta_col[i], curr.distance + 1};
        if (IsValid(next.row, next.col, grid)) {
          pq.push(next);
          grid[curr.row][curr.col] = 1; // visited
        }
      }
    }
    return -1;
  }
};

struct Test {
  vector<vector<int>> grid;
  int expected;
};

int main (void) {
  vector<Test> tests = {
    {
      {
        {0,0,1},
        {0,1,0},
        {1,1,0},
      },
      4
    },
    {
      {
        {0,1},
        {1,0},
      },
      2
    },
    {
      {
        {0,0,0},
        {1,1,0},
        {1,1,0},
      },
      4
    },
    {
      {
        {0,0,1},
        {0,1,0},
        {1,0,0},
      },
      4
    },
    {
      {
        {1,0,0},
        {1,1,0},
        {1,1,0}
      },
      -1,
    },
    {
      {
        {0,0,0},
        {1,1,0},
        {1,1,1}
      },
      -1,
    }
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.shortestPathBinaryMatrix(test.grid);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;

  return 0;
}