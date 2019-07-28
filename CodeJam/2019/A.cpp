#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long int getIndexContains4(long int N) {
  long int x;
  long int result = 0;
  while (N) {
    x = N % 10;
    if (x == 4) return result;
    N /= 10;
    result++;
  }
  return -1;
}

pair<long int, long int> getNWitout4(long int N) {
  long int A = N, B = 1;
  long int index;
  while (true) {
    index = getIndexContains4(A);
    if (index == -1) {
      return make_pair(A, N - A); // result
    }
    B = pow(10, index);
    A -= B;
  }
}

int main(void) {
  int tc, c = 1;
  long int n;
  pair<long int, long int> result;
  cin >> tc;
  while (tc--) {
    cin >> n;
    result = getNWitout4(n);
    cout << "Case #" << c << ": " << result.first << " " <<  result.second << endl;
    c++;
  }
  return 0;
}
