#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct myPoint {
  int x;
  int y;
  double distance_to_origin;
  myPoint(int _x, int _y) : x(_x), y(_y) {}

  void calculateDistance() {
    distance_to_origin = sqrt((x * x) + (y * y));
  }
};

bool myPointCompare(myPoint a, myPoint b) {
  return a.distance_to_origin < b.distance_to_origin;
}

vector<myPoint> calculateDistances(vector<vector<int>>& myPoints) {
  vector<myPoint> result;
  for (auto v : myPoints) {
    myPoint p(v[0], v[1]);
    p.calculateDistance();
    result.push_back(p);
  }
  return result;
}

vector<vector<int>> kClosest(vector<vector<int>>& input, int K) {
  vector<vector<int>> result;
  vector<myPoint> myPoints = calculateDistances(input);
  sort(myPoints.begin(), myPoints.end(), myPointCompare);
  for (int i = 0; i < K; i++) {
    myPoint p = myPoints[i];
    result.push_back({p.x, p.y});
  }
  return result;
}

int main(void) {
  vector<vector<int>> myPoints = {
    {1,3},
    {-2,2}
  };
  int K = 1;
  kClosest(myPoints, K);
}
