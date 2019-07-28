#include <bits/stdc++.h>
using namespace std;
#define inf numeric_limits<int>::max()

void merge(int A[],int p, int q, int r) {
  int n1, n2, i, j;
  n1 = q-p+1;
  n2 = r-q;
  int L[n1+1], R[n2+1];

  for (i = 0; i < n1; i++)
    L[i] = A[p+i];
  for (j = 0; j < n2; j++)
    R[j] = A[q+j+1];

  L[n1] = inf;
  R[n2] = inf;

  i = j = 0;
  for (int k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void merge_sort(int A[],int p, int r) {
  if (p < r) {
    int q = (p+r)/2;
    merge_sort(A,p,q);
    merge_sort(A,q+1,r);
    merge(A,p,q,r);
  }
}

int main(void) {
  int A[] = {12,11,13,5,6,7};
  int size = (sizeof(A)/sizeof(*A));
  merge_sort(A,0,size-1);
  for (int i = 0; i < size; i++)
    cout << A[i] << endl;
  return 0;
}
