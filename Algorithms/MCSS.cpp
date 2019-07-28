#include <bits/stdc++.h>
using namespace std;

int MCSS(int A[], int len) {
  int max, sum, start, end, i;
  max = sum = start = end = i = 0;
  for (int j = 0; j < len; j++) {
    sum += A[j];
    if (sum > max) {
      max = sum;
      start = i;
      end = j;
    } else if (sum < 0) {
      i = j + 1;
      sum = 0;
    }
  }
  return max;
}

int main(void) {
  int A[] = {5,7,-3,1,-11,8,12};
  int len = sizeof(A)/sizeof(*A);
  cout << MCSS(A,len) << endl;
  return 0;
}
