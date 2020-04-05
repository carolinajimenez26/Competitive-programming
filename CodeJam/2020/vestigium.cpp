#include <iostream>
#include <vector>
#include <unordered_set>
#define MAX 110

using namespace std;

int SumDiagonal(const vector<vector<int>>& M, int size) {
  int sum = 0;
  for (int row = 0, col = 0; col < size && row < size; row++, col++) {
    sum += M[row][col];
  }
  return sum;
}

int RepeatedByRow(const vector<vector<int>>& M, int size) {
  int res = 0;
  for (int row = 0; row < size; row++) {
    unordered_set<int> repeated;
    for (int col = 0; col < size; col++) {
      int x = M[row][col];
      if (repeated.count(x) > 0) {
        res++;
        break;
      } else {
        repeated.insert(x);
      }
    }
  }
  return res;
}

int RepeatedByCol(const vector<vector<int>>& M, int size) {
  int res = 0;
  for (int col = 0; col < size; col++) {
    unordered_set<int> repeated;
    for (int row = 0; row < size; row++) {
      int x = M[row][col];
      if (repeated.count(x) > 0) {
        res++;
        break;
      } else {
        repeated.insert(x);
      }
    }
  }
  return res;
}

int main(void) {
  int tc, N;
  vector<vector<int>> M(MAX, vector<int>(MAX));
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cin >> N;
    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++) {
        cin >> M[row][col];
      }
    }
    int k = SumDiagonal(M, N);
    int r = RepeatedByRow(M, N);
    int c = RepeatedByCol(M, N);
    cout << "Case #" << i << ": " << k << " " << r << " " << c << endl;
  }
  return 0;
}