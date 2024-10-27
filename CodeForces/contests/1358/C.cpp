#include <iostream>
using namespace std;
using int64 = long long int;

struct Point {
  int row, col;
};

bool SameRow(Point a, Point b) {
  return a.row == b.row;
}

bool SameCol(Point a, Point b) {
  return a.col == b.col;
}

int64 Diff(Point a, Point b) {
  int64 row_diff = b.row - a.row;
  int64 col_diff = b.col - a.col;
  return row_diff + col_diff;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int x1,y1,x2,y2;
    int64 ans = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1{y1,x1}, p2{y2,x2};
    if (SameRow(p1,p2) || SameCol(p1,p2)) {
      ans = 1;
    } else {
      int diff = Diff(p1,p2);
      if (diff <= 4) ans = diff;
      else ans = 2 * diff - 1; 
    }
    cout << ans << endl;
  }
  return 0;
}