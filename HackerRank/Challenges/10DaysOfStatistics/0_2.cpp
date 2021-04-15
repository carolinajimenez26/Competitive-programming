#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetMedian(const vector<int>& v, int from, int to) {
  int len = (to - from);
  int mid = (len / 2) + from;
  if (len % 2 == 0) {
    return (v[mid] + v[mid - 1]) / 2;
  }
  return v[mid];
}

vector<int> quartiles(vector<int> v) {
  vector<int> result;
  sort(v.begin(), v.end());
  int mid = v.size() / 2;
  int Q2 = GetMedian(v, 0, v.size());
  int Q1 = GetMedian(v, 0, mid);
  int Q3; 
  if (v.size() % 2 == 0) {
    Q3 = GetMedian(v, mid, v.size());
  } else {
    Q3 = GetMedian(v, mid + 1, v.size());
  }
  return {Q1, Q2, Q3};
}

struct Test {
  vector<int> v;
  vector<int> expected;
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  vector<Test> tests = {
    { {9,5,7,1,3}, {2,5,8} },
    { {18, 45, 55, 70, 76, 83, 88, 90, 92, 92, 95, 98}, {62, 85, 92} },
    { {2,3,4,5,6,7,9}, {3,5,7} },
    { {1,3,5,7}, {2,4,6} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    vector<int> out = quartiles(test.v);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      Print(out);
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}