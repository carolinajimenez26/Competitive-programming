#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Cell {
  int row, col, val;

  void print() {
    cout << row << ", " << col << ": " << val << endl;
  }
};

struct cmp {
  bool operator() (const Cell &a , const Cell &b ) {
    return a.val > b.val;
  }
};

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }
    int INF = numeric_limits<int>::max();
    vector<vector<int>> distances(grid.size(), vector<int>(grid[0].size(), INF));
    distances[0][0] = grid[0][0];
    Dijkstra(grid, distances);
    return distances[grid.size() - 1][grid[0].size() - 1];
  }
private:
  void Dijkstra(const vector<vector<int>>& grid, vector<vector<int>> &distances) {
    // right and down
    vector<int> dirs_row = {0,1};
    vector<int> dirs_col = {1,0};
    priority_queue<Cell, vector<Cell>, cmp> Q;
    Q.push({0,0, grid[0][0]});
    while (!Q.empty()) {
      Cell current = Q.top();
      // current.print();
      Q.pop();
      for (int i = 0; i < dirs_row.size(); i++) { // neighbors
        int row, col;
        row = current.row + dirs_row[i];
        col = current.col + dirs_col[i];
        if (!Valid(grid, row, col)) {
          continue;
        }
        int weight = distances[current.row][current.col] + grid[row][col];
        if (weight < distances[row][col]) {
          distances[row][col] = weight;
          Cell neighbor{row, col, grid[row][col]};
          Q.push(neighbor);
        }
      }
    }
  }
  inline bool Valid(const vector<vector<int>>& grid, int row, int col) {
    return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
  }
};

int main(void) {
  vector<vector<int>> grid = {
    {1,3,1},
    {1,5,1},
    {4,2,1}
  };
  Solution sol;
  cout << sol.minPathSum(grid) << endl;
}