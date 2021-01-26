#include <iostream>
#include <vector>
using namespace std;

struct Position {
  int row, col;

  bool operator==(const Position& other) {
    return row == other.row && col == other.col;
  }

  void Print() {
    cout << "{" << row << ", " << col << "}" << endl;
  }
};

class Solution {
public:
  int minimumEffortPath(vector<vector<int>>& heights_) {
    if (heights_.empty()) {
      return 0;
    }
    heights = heights_;
    int rows = heights.size();
    int cols = heights[0].size();
    const int MAX = 1e6 + 4;
    int left = 0, right = MAX;
    Position initial = {0,0};
    Position target = {rows - 1, cols - 1 };
    // [0,0,0,0,0,1,1,1,1,1]
    while (left < right) {
      int mid = (left + right) / 2;
      visited.assign(rows, vector<bool>(cols, false));
      if (ThereIsPath(initial, mid, target)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
private:
  vector<vector<int>> heights;
  vector<vector<bool>> visited;
  vector<int> delta_row = {-1, 0, 1, 0};
  vector<int> delta_col = { 0, 1, 0, -1};

  bool IsValid(Position pos) {
    return pos.row >= 0 && pos.row < heights.size() && 
           pos.col >= 0 && pos.col < heights[0].size();
  }

  bool ThereIsPath(Position curr, int max_edge, Position target) {
    if (!IsValid(curr)) {
      return false;
    }
    if (curr == target) {
      return true;
    }
    visited[curr.row][curr.col] = true;
    bool ans = false;
    for (int i = 0; i < delta_row.size(); i++) {
      Position next = {delta_row[i] + curr.row, delta_col[i] + curr.col};
      if (!IsValid(next) || visited[next.row][next.col]) {
        continue;
      }
      int edge = abs(heights[curr.row][curr.col] - heights[next.row][next.col]);
      if (edge > max_edge) {
        continue;
      }
      ans |= ThereIsPath(next, max_edge, target);
    }
    return ans;
  }
};

int main(void) {
  vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
  Solution sol;
  cout << sol.minimumEffortPath(heights) << endl;
  return 0;
}