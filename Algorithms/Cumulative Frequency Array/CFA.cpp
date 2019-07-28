// Cumulative Frequency Array: For Range Sum Queries
#include <bits/stdc++.h>
using namespace std;

int* prefix_sum(int A[], int len) {
  int sum = A[0];
  int* B = new int[len];
  B[0] = A[0];
  for (int i = 1; i < len; i++) {
    sum += A[i];
    B[i] = sum;
  }
  return B;
}

void print(int X[], int size) {
  for (int i = 0; i < size; i++) {
    cout << X[i] << " " ;
  }
  cout << endl;
}

int main(void) {
  int A[] = {3,12,6,9,17,4,3,2,19};
  int len = sizeof(A)/sizeof(*A);
  int* B = new int[len];
  B = prefix_sum(A,len);
  print(B,len);
  cout << B[7] - B[1] << endl;
  delete B;
  return 0;
}
