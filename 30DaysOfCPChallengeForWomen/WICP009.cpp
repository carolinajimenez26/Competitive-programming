#include <iostream>
#include <vector>

using namespace std;

template <class T>
void print(const vector<vector<T>>& grid, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void PrefixSumLeftRight(const vector<vector<char>>& grid, int size, vector<vector<int>>& result) {
  for (int row = 0; row < size; row++) {
    int sum = 0;
    for (int col = size - 1; col >= 0; col--) {
      sum += (grid[row][col] == '#' ? 1 : 0);
      result[row][col] = sum;
    }
  }
}

void PrefixSumDownUp(const vector<vector<char>>& grid, int size, vector<vector<int>>& result) {
  for (int col = 0; col < size; col++) {
    int sum = 0;
    for (int row = size - 1; row >= 0; row--) {
      sum += (grid[row][col] == '#' ? 1 : 0);
      result[row][col] = sum;
    }
  }
}

int HowManyCellsForMirror(const vector<vector<char>>& grid, int size) {
  vector<vector<int>> left_right(size, vector<int>(size, 0));
  vector<vector<int>> down_up(size, vector<int>(size, 0));

  PrefixSumLeftRight(grid, size, left_right);
  // print(left_right, size);
  PrefixSumDownUp(grid, size, down_up);
  // print(down_up, size);

  int result = 0;
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (left_right[row][col] == 0 && down_up[row][col] == 0) {
        result++;
      }
    }
  }
  return result;
}

int main(void) {
  int tc, N;
  vector<vector<char>> grid(1005, vector<char>(1005));
  cin >> tc;
  while (tc) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> grid[i][j];
      }
    }
    // print(grid, N);
    cout << HowManyCellsForMirror(grid, N) << endl;
    tc--;
  }
  return 0;
}