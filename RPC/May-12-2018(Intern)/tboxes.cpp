#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
  long int N, x, min = numeric_limits<long int>::max(), max = numeric_limits<long int>::min();
  cin >> N;
  for (long int i = 0; i < N; i++) {
    cin >> x;
    if (x < min) {
      min = x;
    }
    if (x > max) {
      max = x;
    }
    cout << (min + max) << endl;
  }
  return 0;
}
