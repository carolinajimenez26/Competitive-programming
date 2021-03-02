#include <iostream>
#include <vector>
using namespace std;
const int INF = numeric_limits<int>::max();

bool IsValid(const vector<vector<int>>& arr, int row, int col) {
  return row >= 0 && row < arr.size() 
          && col >= 0 && arr.size() > 0 && col < arr[0].size();
}

int GetSum(const vector<vector<int>>& arr, int row, int col) {
  int result = 0;
  for (int i = 0; i < 3; i++) {
    if (!IsValid(arr, row, col + i)) {
      return -INF;
    }
    result += arr[row][col + i];
  }
  if (!IsValid(arr, row + 1, col + 1)) {
    return -INF;
  }
  result += arr[row + 1][col + 1];
  row += 2;
  for (int i = 0; i < 3; i++) {
    if (!IsValid(arr, row, col + i)) {
      return -INF;
    }
    result += arr[row][col + i];
  }
  return result;
}

int hourglassSum(vector<vector<int>> arr) {
  int best = -INF;
  for (int row = 0; row < arr.size(); row++) {
    for (int col = 0; col < arr[0].size(); col++) {
      best = max(best, GetSum(arr, row, col));
    }
  }
  return best;
}

int main(void) {
  return 0;
}