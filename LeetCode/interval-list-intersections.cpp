#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool intersects(Interval a, Interval b) {
  Interval bigger = a, smaller = b;
  if (b.end > a.end) {
    bigger = b;
    smaller = a;
  }
  if (smaller.end < bigger.start) return false;
  return true;
}

Interval getInterval(Interval a, Interval b) {
  int max_n = min(a.end, b.end);
  int min_n = max(a.start, b.start);
  return Interval(min_n, max_n);
}

vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
  vector<Interval> result;
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B.size(); j++) {
      if (intersects(A[i], B[j]))
        result.push_back(getInterval(A[i], B[j]));
      if (A[i].end < B[j].start) break;
    }
  }
  return result;
}

int main(void) {
  // print(intervalIntersection());
  return 0;
}
