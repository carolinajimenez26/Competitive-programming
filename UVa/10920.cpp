#include <bits/stdc++.h>
#define sol(x, y) cout << "Line = " << x << ", column = " << y << "." << endl;
using namespace std;

void find(long long p, long long from, long long to, long long middle, long long size,
          long long real_size) {
  long long line, column;
  line = column = middle + (size / 2);
  long long tmp;
  for (long long i = 0; i < 4; i++) {
    tmp = to - size + 1;
    if (p <= to and p >= tmp) {
      // cout << "It is between " << to << " and "
      //      << (tmp < to and i % 2 ? size * size : tmp) << endl;

      if (i == 0) { // move rows
        line -= (to - p);
        break;
      }
      if (i == 1) { // move rows and columns
        line = real_size - line + 1;
        column -= (to - p);
        break;
      }
      if (i == 2) { // move rows and columns
        column = real_size - column + 1;
        line = middle - (size / 2);
        line += (to - p);
        break;
      }
      if (i == 3) { // move columns
        column = middle - (size / 2);
        column += (to - p);
      }
    }
    to = tmp;
  }
  sol(line, column);
}

int main(void) {
  long long sz, p;
  while (cin >> sz >> p) {
    if (!sz and !p) break;
    long long middle = (sz / 2) + 1;
    if (p == 1) {
      sol(middle, middle);
    } else {
      long long from = 2, to;
      for (long long i = 3; i <= sz; i += 2) {
        to = i * i;
        if (p >= from and p <= to) {
          // cout << "It is between " << from << " and " << to << endl;
          find(p, from, to, middle, i, sz);
        }
        from = to + 1;
      }
    }
  }
  return 0;
}
