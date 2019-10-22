#include <iostream>
#include <vector>
#include <set>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

class Solution {
private:
  vector<vector<int>> grid;
  set<pair<int,int>> used;
  vector<int> row_dirs = {-1, 0, 1, 0};
  vector<int> col_dirs = { 0, 1, 0,-1};
public:
  bool IsValid(int row, int col) {
    return row >= 0 && row < grid.size() &&
           col >= 0 && col < grid[0].size() && 
           used.find({row,col}) == used.end() && 
           grid[row][col] != 0;
  }

  int CollectMaximum(int row, int col) {
    if (!IsValid(row, col)) {
      return 0;
    }
    used.insert({row, col});
    int best = 0;
    for (int dir = 0; dir < row_dirs.size(); dir++) {
      int new_row = row + row_dirs[dir];
      int new_col = col + col_dirs[dir];
      int collected = CollectMaximum(new_row, new_col);
      best = max(best, collected);
    }
    used.erase({row, col});
    return best + grid[row][col];;
  }

  int GetMaximumGold() {
    int best = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == 0) {
          continue;
        }
        int collected = CollectMaximum(row, col);
        best = max(best, collected);
      }
    }
    return best;
  }

  int getMaximumGold(vector<vector<int>>& grid_) {
    grid = grid_;
    vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
    return GetMaximumGold();
  }
};

int main(void) {
  vector<vector<int>> grid = {
    {0,6,0},
    {5,8,7},
    {0,9,0}
  };
  Solution sol;
  cout << sol.getMaximumGold(grid) << endl;
  return 0;
}