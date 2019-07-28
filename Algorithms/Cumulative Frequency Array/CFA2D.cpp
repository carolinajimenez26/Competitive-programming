// Cumulative Frequency Array: For Range Sum Queries
#include <bits/stdc++.h>
using namespace std;
const int rows = 3, cols = 4;

void print(int *X) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << X[i * cols + j] << " " ;
    }
    cout << endl;
  }
  cout << endl;
}

void prefix_sum_row(int *A, int i) {
  int j = 0;
  int sum = A[i * cols + j];
  j++;
  for (; j < cols; j++) {
    sum += A[i * cols + j];
    A[i * cols + j] = sum;
  }
}

void prefix_sum_col(int *A, int j) {
  int i = 0;
  int sum = A[i * cols + j];
  i++;
  for (; i < rows; i++) {
    sum += A[i * cols + j];
    A[i * cols + j] = sum;
  }
}

void prefix_sum(int *A) {
  for (int i = 0; i < rows; i++) {
    prefix_sum_row(A,i);
  }
  for (int j = 0; j < cols; j++) {
    prefix_sum_col(A,j);
  }
}

void receive(int *X) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> X[i * cols + j];
    }
  }
}

int main(void) {
  auto A = new int[rows * cols];
  receive(A);
  prefix_sum(A);
  print(A);
  cout << A[1 * cols + 2] << endl;
  delete A;
  return 0;
}
