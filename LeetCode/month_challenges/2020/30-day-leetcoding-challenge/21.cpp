#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;


// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
public:
  int get(int x, int y) {
    return M[x][y];
  }
  vector<int> dimensions() {
    int n = M.size();
    int m = n > 0 ? M[0].size() : 0;
    return {n,m};
  }
  BinaryMatrix(vector<vector<bool>>& _M) : M(_M) {}
private:
  vector<vector<bool>> M;
};

class Solution {
public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int> dimensions = binaryMatrix.dimensions();
    if (dimensions[0] == 0 || dimensions[1] == 0) return -1;
    int result = dimensions[1]; // invalid
    for (int row = 0; row < dimensions[0]; row++) {
      // find first col with a 1
      int idx = BinarySearch(row, 0, dimensions[1] - 1, 1, binaryMatrix);
      if (idx != -1) {
        result = min(result, idx);
      }
    }
    return result == dimensions[1] ? -1 : result;
  }
private:
  int BinarySearch(int row, int left, int right, int x, BinaryMatrix &binaryMatrix) {
    while (left < right) {
      int mid = (left + right) / 2;
      int n = binaryMatrix.get(row, mid);
      if (n < x) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return (binaryMatrix.get(row, left) == x ? left : -1);
  }
};

int main(void) {
  vector<vector<bool>> M = {
    {0,0},
    {1,1}
  };
  BinaryMatrix bm(M);
  Solution sol;
  cout << sol.leftMostColumnWithOne(bm) << endl;
  return 0;
}