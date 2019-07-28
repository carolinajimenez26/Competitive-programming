#include <iostream>
#include <vector>

using namespace std;

const vector<int> dirs_row = {-1,0,1,0};
const vector<int> dirs_col = {0,1,0,-1};

class Solution {
  bool IsValid(vector<vector<int>>& A, int x, int y) {
    return x >= 0 && x < A.size() && y >= 0 && y < A[0].size();
  }

  int DFS(vector<vector<int>>& g, int x, int y) {
    int ans = 1;
    g[x][y] = 5;
    for (int i = 0; i < 4; i++) {
      int nx = x + dirs_row[i];
      int ny = y + dirs_col[i];
      if (IsValid(g, nx, ny) && g[nx][ny] == 1) {
        ans += DFS(g, nx, ny);
      }
    }
    return ans;
  }

 public:

  int numEnclaves(vector<vector<int>>& A) {
    const int n = A.size() + 2;
    const int m = A[0].size() + 2;
    vector<vector<int>> B(n, vector<int>(m, 1));
    int sea = 0;
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        B[i][j] = A[i - 1][j - 1];
        sea += (A[i-1][j-1] == 0);
      }
    }
    return n * m - DFS(B, 0, 0) - sea;
  }
};

int main(void) {
  vector<vector<int>> input = {{0,0,0},{0,1,0},{0,1,0},{0,1,0},{0,0,0}};
  Solution sol;
  cout << sol.numEnclaves(input) << endl;
  return 0;
}
