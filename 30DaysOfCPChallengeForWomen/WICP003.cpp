#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(size)
long long GetSum(const vector<int>& A, int size, int M) {
  long long S = 0;
  for (int i = 0; i < size; i++) {
    S += max(A[i] - M, 0);
  }
  return S;
}

// O(size * log (1e9))
pair<int,long long> GetMaxWithThresold(const vector<int>& A, int size, int t) {
  int M, left = 1, right = 1e9, mid;
  long long S;
  while (left < right) {
    mid = (left + right + 1) / 2;
    S = GetSum(A, size, mid);
    if (S >= t) { // there is a valid answer from 0 to mid already
      left = mid;
    } else { // all the results from mid to the end are not valid
      right = mid - 1;
    }
  }
  M = right;
  S = GetSum(A, size, M);
  return {M, S};
}

void print(const vector<int>& v, int size) {
  for (int i = 0; i < size; i++) cout << v[i] << " ";
  cout << endl;
}

int main(void) {
  int tc, N, Th;
  vector<int> A(100005);
  cin >> tc;
  while (tc) {
    cin >> N >> Th;
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    // print(A, N);
    sort(A.begin(), A.begin() + N);
    // print(A, N);
    pair<int,long long> result = GetMaxWithThresold(A, N, Th);
    cout << result.first << " " << result.second << endl;
    tc--;
  }
  return 0;
}