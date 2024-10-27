#include <iostream>
#include <cassert>
// #include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << x << endl
using namespace std;
using int64 = long long int;
const int64 WALL_DIMENSION = 2e9;
const int64 X_Y_MAX = 1e9;

struct Point {
  int64 x, y;
};

struct BSResult {
  string res;
  int64 x, y;
};

Point GetNextPoint(Point& from, int64 radius) {
  from.x = from.x + radius;
  if (from.x > (WALL_DIMENSION / 2)) {
    from.y = from.y - radius;
    from.x = -(WALL_DIMENSION / 2);
  }
  return from;
}

void MoveHorizontal(int64& left, int64& right, int64 mid, bool op, const string& res) {
  if (op) {
    if (res == "HIT") {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  } else {
    if (res == "HIT") {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
}

BSResult BinarySearchHorizontal(int64 left, int64 right, int64 y, bool op, int& i) {
  string res;
  // dbg(op);
  while (i-- && left < right) {
    int64 mid = (left + right) / 2;
    // dbg(left);dbg(right);dbg(mid);
    cout << mid << " " << y << endl;
    cin >> res;
    assert(res != "WRONG");
    if (res == "CENTER") {
      return {res, mid, y};
    }
    MoveHorizontal(left, right, mid, op, res);
  }
  return {"", left, y};
}

void MoveVertical(int64& up, int64& down, int64 mid, bool op, const string& res) {
  if (op) {
    if (res == "HIT") {
      down = mid + 1;
    } else {
      up = mid - 1;
    }
  } else {
    if (res == "HIT") {
      up = mid - 1;
    } else {
      down = mid + 1;
    }
  }
}

BSResult BinarySearchVertical(int64 up, int64 down, int64 x, bool op, int& i) {
  string res;
  // dbg(op);
  while (i-- && up > down) {
    int64 mid = (up + down) / 2;
    // dbg(up);dbg(down);dbg(mid);
    cout << x << " " << mid << endl;
    cin >> res;
    assert(res != "WRONG");
    if (res == "CENTER") {
      return {res, x, mid};
    }
    MoveVertical(up, down, mid, op, res);
  }
  return {"", x, up};
}

int main(void) {
  int T;
  int64 A, B;
  string res;
  cin >> T >> A >> B;
  while (T--) {
    int64 x_from, x_to, y_from, y_to;
    Point from{-X_Y_MAX, X_Y_MAX};
    // Point to{X_Y_MAX - A, X_Y_MAX - A};
    int i = 300;
    Point p;
    int64 x_left, x_right, y_up, y_down;
    BSResult result;
    while (i--) {
      if (i == 300 - 1) {
        p = from;
      } else {
        p = GetNextPoint(from, A);
      }
      cout << p.x << " " << p.y << endl;
      cin >> res;
      assert(res != "WRONG");
      if (res == "CENTER" || res == "HIT") {
        break;
      }
    }
    if (res == "CENTER") {
      break; // start new test case
    }
    while (i--) {
      // find the first x that doesn't hit going to the left of p.x
      result = BinarySearchHorizontal(-WALL_DIMENSION / 2, p.x, p.y, true, i);
      if (result.res == "CENTER" || i == 0) {
        break;
      }
      x_left = result.x + 1;
      // dbg(x_left);

      // find the LAST x that hits going to the right of p.x
      result = BinarySearchHorizontal(p.x, WALL_DIMENSION / 2, p.y, false, i);
      if (result.res == "CENTER" || i == 0) {
        break;
      }
      x_right = result.x;
      // dbg(x_right);

      // find the first y that doesn't hit going up from p.y
      result = BinarySearchVertical(WALL_DIMENSION / 2, p.y, p.x, true, i);
      if (result.res == "CENTER" || i == 0) {
        break;
      }
      y_up = result.y - 1;
      // dbg(y_up);

      // find the last y that hits going down from p.y
      result = BinarySearchVertical(p.y, -WALL_DIMENSION / 2, p.x, false, i);
      if (result.res == "CENTER" || i == 0) {
        break;
      }
      y_down = result.y;
      // dbg(y_down);

      cout << ((x_left + x_right) / 2) << " " << ((y_up + y_down) / 2) << endl;
      cin >> res;
      if (res == "CENTER") {
        break;
      } else {
        assert(false);
      }
    }
  }
  return 0;
}