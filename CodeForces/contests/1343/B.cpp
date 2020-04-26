#include <iostream>
#include <vector>
#define MAX 2e5 + 5
using namespace std;

void print(const vector<int>& v, int size) {
  for (int i = 0; i < size; i++) {
    cout << v[i];
    if (i != size - 1) cout << " ";
  }
  cout << endl;
}

int main(void) {
  int tc, n;
  vector<int> A(MAX);
  cin >> tc;
  while (tc--) {
    cin >> n;
    int x = 2, sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 2; i++) {
      A[i] = x;
      x += 2;
      sum1 += A[i];
    }
    x = 1;
    for (int i = n / 2; i < n - 1; i++) {
      A[i] = x;
      x += 2;
      sum2 += A[i];
    }
    int last = sum1 - sum2;
    if (last % 2 == 0) {
      cout << "NO" << endl;
    } else {
      A[n - 1] = last;
      cout << "YES" << endl;
      print(A, n);
    }
  }
  return 0;
}