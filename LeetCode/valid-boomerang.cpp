#include <iostream>
#include <vector>
#include <limits>
#include <cassert>
using namespace std;

struct RectEcuation {
  const double delta = 1e-9;
  double m, b;

  RectEcuation(double m_, double b_) : m(m_), b(b_) {}

  bool operator==(const RectEcuation& other) const {
    return (abs(m - other.m) <= delta) && (abs(b - other.b) <= delta);
  }
};

struct Point {
  int x, y;

  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }

  bool operator!=(const Point& other) const {
    return x != other.x || y != other.y;
  }
};

class Solution {
public:
  bool isBoomerang(vector<vector<int>>& points) {
    assert("Should be 3 valid points" && points.size() == 3);
    Point p1 = {points[0][0], points[0][1]};
    Point p2 = {points[1][0], points[1][1]};
    Point p3 = {points[2][0], points[2][1]};

    if (!Differents(p1,p2,p3)) {
      return false;
    }

    double slope_p1p2 = GetSlope(p1,p2);
    RectEcuation rect_ecuation_p1p2 = {slope_p1p2, GetInclination(slope_p1p2, p1)};

    double slope_p1p3 = GetSlope(p1,p3);
    RectEcuation rect_ecuation_p1p3 = {slope_p1p3, GetInclination(slope_p1p3, p1)};

    return !(rect_ecuation_p1p2 == rect_ecuation_p1p3);
  }
private:
  const int INF = numeric_limits<int>::max();

  double GetSlope(Point p1, Point p2) {
    double delta_y = p2.y - p1.y;
    double delta_x = p2.x - p1.x;
    if (delta_x == 0) {
      return INF;
    }
    return (delta_y / delta_x);
  }

  double GetInclination(double slope, Point p) {
    // y = mx + b => b = y - mx
    if (slope == INF) {
      return INF;
    }
    return (p.y - slope * p.x);
  }

  bool Differents(Point a, Point b, Point c) {
    return (a != b && a != c && b != c);
  }
};

struct Test {
  vector<vector<int>> points;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    { {{1,1},{2,3},{3,2}}, true },
    { {{1,1},{2,2},{3,3}}, false },
    { {{0,1},{0,1},{2,1}}, false },
    { {{0,0},{1,2},{0,1}}, true },
    { {{0,1},{1,0},{0,1}}, false },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.isBoomerang(test.points);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}