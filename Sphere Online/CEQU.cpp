#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
  if (a == 0) {
      x = 0; y = 1;
      return b;
  }
  int x1, y1;
  int d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

int main(void) {
  int T, a, b, c, counter, x, y;
  cin >> T;
  counter = 1;
  while (T--) {
    cin >> a >> b >> c;
    cout << "Case " << counter << ": "
         << ((c % gcd(a, b, x, y)) == 0 ? "Yes" : "No")
         << endl;
    counter++;
  }
  return 0;
}
