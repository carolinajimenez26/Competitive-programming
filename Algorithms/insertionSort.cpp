#include <bits/stdc++.h>
using namespace std;

void swap(int (&A)[6], int i, int j) {
  int tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

int main(void){
  int A[] = {5,2,4,6,1,3};
  int key, i, tmp;
  int size = (sizeof(A)/sizeof(*A));

  for (int j = 1; j < size; j++) {
    key = A[j];
    i = j - 1;
    while (i >= 0 and A[i] > key) {
      swap(A,i,i+1);
      i--;
    }
  }

  for (int j = 0; j < size; j++) {
    cout << A[j] << endl;
  }

  return 0;
}
