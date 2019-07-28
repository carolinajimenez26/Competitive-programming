#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v) {
  for (auto& e : v) {
    cout << e << " ";
  }
  cout << endl;
}

void print(vector<vector<int>>& matrix) {
  for (auto& row : matrix) {
    print(row);
  }
  cout << endl;
}

int fastPower(unsigned int base, unsigned int power) {
  int result = 1;
  while (power > 0) {
    if (power % 2 == 0) {
      power /= 2;
      base *= base;
    } else {
      power -= 1;
      result *= base;
      power /= 2;
      base *= base;
    }
  }
  return result;
}

int getDecimalValue(vector<int>& v) { // O (v.size())
  int result = 0;
  for (int i = 0; i < v.size(); i++) {
    result += v[i] ? fastPower(2, v.size() - 1 - i) : 0;
  }
  return result;
}

vector<int> getRowsScore(vector<vector<int>>& A, int& totalScore) { // O (rowsA * colsA)
  vector<int> result;
  for (int row = 0; row < A.size(); row++) { // O (A.size())
    int sumRow = getDecimalValue(A[row]); // O (A[row].size())
    result.push_back(sumRow);
    totalScore += sumRow;
  }
  return result;
}

vector<int> toggle(vector<int>& v) {
  vector<int> result(v.size());
  for (int i = 0; i < v.size(); i++) {
    if (v[i]) result[i] = 0;
    else result[i] = 1;
  }
  return result;
}

// O (colsA)
void maximizeRow(vector<vector<int>>& A, int row, vector<int>& rowValues, int& totalScore) {
  A[row] = toggle(A[row]); // O (colsA)
  int toggledRowValue = getDecimalValue(A[row]); // O (A[row].size()) = O (colsA)
  totalScore += (toggledRowValue - rowValues[row]);
  rowValues[row] = toggledRowValue;
}

// O (rowsA) * O (log(colsA))
void toggleColumn(vector<vector<int>>& A, vector<int>& rowValues, int& totalScore, int col) {
  int newRowValue = 0;
  for (int row = 0; row < A.size(); row++) { // O (rowsA)
    int columnValue = fastPower(2, A[0].size() - 1 - col); // O (log(colsA))
    if (A[row][col] == 1) {
      newRowValue = rowValues[row] - columnValue;
      totalScore -= columnValue;
    } else { // 0
      newRowValue = rowValues[row] + columnValue;
      totalScore += columnValue;
    }
    rowValues[row] = newRowValue;
  }
}

// O (colsA) * O (rowsA) * O (log(colsA))
void maximizeColumns(vector<vector<int>>& A, vector<int>& rowValues, int& totalScore) {
  for (int col = 0; col < A[0].size(); col++) { // O (colsA)
    int zeros = 0;
    for (int row = 0; row < A.size(); row++) { // O (rowsA)
      if (A[row][col] == 0) zeros++;
    }
    int ones = A.size() - zeros;
    if (zeros > ones) toggleColumn(A, rowValues, totalScore, col); // O (rowsA) * O (log(colsA))
  }
}

// O (rowsA) * O (colsA) * O (log(colsA))
int matrixScore(vector<vector<int>>& A) {
  int totalScore = 0;
  vector<int> rowValues = getRowsScore(A, totalScore);
  // cout << "rowValues: "; print(rowValues);
  for (int row = 0; row < A.size(); row++) // O (rowsA)
    if (A[row][0] == 0) maximizeRow(A, row, rowValues, totalScore); // O (colsA)

  // print(A);
  // cout << "rowValues: "; print(rowValues);
  maximizeColumns(A, rowValues, totalScore); // O (colsA) * O (rowsA) * O (log(colsA))
  return totalScore;
}

int main(void) {
  //{{0,0,1,1},{1,0,1,0},{1,1,0,0}};
  vector<vector<int>> input = {{1,1,1,1,0,1,1,1,0,1,0,0,1,0,0,1,1,0,1,1},{1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1},{1,1,0,0,1,0,0,1,0,0,0,0,1,1,1,1,0,0,0,1},{0,1,0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0},{1,1,1,0,1,0,1,0,1,1,0,0,1,0,1,0,1,0,0,0},{0,1,0,0,0,1,0,1,1,0,1,1,1,0,0,0,1,0,1,1},{1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,1,1,0,0,1},{0,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,1,1,1,1},{1,0,0,0,1,1,0,1,1,1,1,1,1,0,1,0,0,0,1,1},{1,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1,1,0,0,1},{0,1,1,1,0,0,1,0,1,0,1,1,0,1,1,1,0,1,1,0},{0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,1,0,1,1,0},{0,0,1,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0},{1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,0,1,0,1,0},{1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1,0},{1,1,1,1,1,0,0,0,1,0,0,0,1,1,0,1,0,1,1,0},{0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,1},{1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1},{1,0,0,0,1,1,0,0,1,0,1,1,0,0,0,1,0,1,1,0},{1,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0}};
  int expectedOutput = 16112383;//39;
  // print(input);
  int output = matrixScore(input);
  if (output == expectedOutput) cout << "Good Job" << endl;
  else {
    cout << "Received: " << output << ", Expected: " << expectedOutput << endl;
    cout << "Keep trying" << endl;
  }
  return 0;
}
