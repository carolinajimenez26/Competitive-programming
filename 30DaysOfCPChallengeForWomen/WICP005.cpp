#include <iostream>
#include <vector>
#define MAX 1e4 + 5

using namespace std;

int GetMaxContSum(const vector<int>& v, int size) {
  if (size == 0) return 0;
  int max_sum = v[0], max_curr = v[0];
  for (int i = 1; i < size; i++) {
    max_curr = max(v[i], max_curr + v[i]);
    max_sum = max(max_sum, max_curr);
  }
  return max_sum;
}

void print(const vector<int>& v, int size) {
  for (int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main(void) {
  int tc, N;
  vector<int> A(MAX);
  cin >> tc;
  while (tc) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    // print(A, N);
    cout << GetMaxContSum(A, N) << endl;
    tc--;
  }
  return 0;
}