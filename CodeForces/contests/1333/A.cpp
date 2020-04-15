#include <iostream>
#include <vector>

using namespace std;

void Print(const vector<vector<char>>& A, int rows, int cols) {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cout << A[row][col];
    }
    cout << endl;
  }
}

int main(void) {
  int tc, n, m;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    vector<vector<char>> A(n, vector<char>(m, 'B'));
    A[n - 1][m - 1] = 'W';
    Print(A, n, m);
  }
  return 0;
}