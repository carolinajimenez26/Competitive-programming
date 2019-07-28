#include <iostream>
#include <vector>

using namespace std;

const vector<int> row_dir = {0, -1, 0, 1};
const vector<int> col_dir = {-1, 0, 1, 0};

bool isValidPosition(const vector<vector<int>>& M, int row, int col) {
  return row >= 0 && row < M.size() && col >= 0 && col < M[0].size();
}

void visitIsland(const vector<vector<int>>& M, vector<vector<int>>& visited,
                int row, int col, int& count) {

  if (!isValidPosition(M, row, col) || M[row][col] == 0 || visited[row][col]) return;
  count++;
  visited[row][col] = 1;
  for (int i = 0; i < 4; i++) {
    visitIsland(M, visited, row + row_dir[i], col + col_dir[i], count);
  }
}

int maxAreaOfIsland(vector<vector<int>>& M) {
  int visited_elements = 0;
  if (M.size() == 0) return 0;
  int R = M.size(), C = M[0].size();
  vector<vector<int>> visited(R, vector<int>(C, 0));
  int max_area = 0;

  for (int i = 0; i < R && visited_elements <= R * C; i++) {
    for (int j = 0; j < C && visited_elements <= R * C; j++) {
      if (M[i][j] == 1 && !visited[i][j]) {
        int area = 0;
        visitIsland(M, visited, i, j, area);
        visited_elements += area;
        if (area > max_area) max_area = area;
      }
      if (!visited[i][j]) {
        visited_elements++;
        visited[i][j] = 1;
      }
    }
  }
  return max_area;
}

int main(void) {
  return 0;
}
