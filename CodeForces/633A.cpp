#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd(b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g) {
      return false;
  }

  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

int main(void) {
  int a, b, c, x, y, g, x_aux, y_aux;
  cin >> a >> b >> c;
  if (find_any_solution(a, b, c, x, y, g)) {
    if (x >= 0 and y >= 0) {
      cout << "Yes" << endl;
    } else {
      for (int i = -c; i <= c; i++) {
        x_aux = x + i * (b / g);
        y_aux = y - i * (a / g);
        if (x_aux >= 0 and y_aux >= 0) break;
      }
      if (x_aux >= 0 and y_aux >= 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}
