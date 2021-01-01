#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) return 0;
    int result = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        result += BFS(grid, row, col, visited);
      }
    }
    return result;
  }
private:
  int BFS(const vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited) {
    if (visited[row][col] || grid[row][col] == '0') {
      return 0;
    }
    vector<int> rows_dir = {-1, 0, 1, 0};
    vector<int> cols_dir = { 0, 1, 0, -1};
    queue<pair<int,int>> q;
    q.push({row, col});
    visited[row][col] = true;
    while (!q.empty()) {
      pair<int,int> cell = q.front();
      q.pop();
      for (int i = 0; i < rows_dir.size(); i++) {
        int new_row = cell.first + rows_dir[i];
        int new_col = cell.second + cols_dir[i];
        if (!Valid(grid, new_row, new_col) || grid[new_row][new_col] == '0' || visited[new_row][new_col]) {
          continue;
        }
        q.push({new_row, new_col});
        visited[new_row][new_col] = true;
      }
    }
    return 1;
  }
  bool Valid(const vector<vector<char>>& grid, int row, int col) {
    return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
  }
};

int main(void) {
  vector<vector<char>> grid = {
    {'1','1','1','1','0',},
    {'1','1','0','1','0',},
    {'1','1','0','0','1',},
    {'0','0','1','0','1',},
  };
  Solution sol;
  cout << sol.numIslands(grid) << endl;
  return 0;
}