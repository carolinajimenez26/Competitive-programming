#include <bits/stdc++.h>
using namespace std;
int A[] = {0,5,13,19,22,41,55,68,72,81,98};

int binary_search(int target) {
  int lo = 0, hi = sizeof(A)/sizeof(*A), mid;
  while (lo <= hi) {
    mid = lo + (hi-lo)/2;
    if (A[mid] == target)
       return mid;
    else if (A[mid] < target)
       lo = mid+1;
    else
       hi = mid-1;
  }
  return -1; // no lo encontró
}

int main(void) {
  int ans = binary_search(55);
  cout << ans << endl;
  return 0;
}
