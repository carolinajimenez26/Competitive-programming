#include <iostream>
#include <vector>

#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

class Solution {
public:
  void print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }

  int GetMaxStop(const vector<vector<int>>& trips) {
    int result = 0;
    for (auto trip : trips) {
      if (trip[2] > result) result = trip[2];
    }
    return result;
  }

  int GetMaxElement(const vector<int>& v) {
    if (v.size() == 0) return -1;
    int result = v[0];
    for (int i = 0; i < v.size(); i++) {
      if (v[i] > result) result = v[i];
    }
    return result;
  }

  void CalculateStops(vector<int>& stops) {
    int prev = 0, tmp;
    for (int i = 0; i < stops.size(); i++) {
      stops[i] += prev;
      prev = stops[i];
    }
  }

  bool CarPooling(vector<vector<int>>& trips, int capacity) {
    int last_stop = GetMaxStop(trips);
    vector<int> stops(last_stop + 1, 0);
    for (auto trip : trips) {
      int people = trip[0];
      int from = trip[1];
      int to = trip[2];
      stops[from] += people;
      stops[to] -= people;
    }
    CalculateStops(stops);
    return GetMaxElement(stops) <= capacity;
  }
};

struct Test {
  vector<vector<int>> trips;
  int capacity;
};

int main(void) {
  vector<Test> tests = {
    {
      {{2,1,5},{3,3,7}},
      4
    },
    {
      {{2,1,5},{3,3,7}},
      5
    },
    {
      {{2,1,5},{3,5,7}},
      3
    },
    {
      {{3,2,7},{3,7,9},{8,3,9}},
      11
    },
    {
      {},
      4
    },
    {
      {},
      0
    },
    {
      {{7,5,6},{6,7,8},{10,1,6}},
      16
    }
  };

  vector<bool> expected = {
    false,
    true,
    true,
    true,
    true,
    true,
    false
  };

  bool succeed = true;

  for (int i = 0; i < tests.size(); i++) {
    Solution sol;
    Test test = tests[i];
    if (sol.CarPooling(test.trips, test.capacity) != expected[i]) {
      succeed = false;
      cout << "Failed on test#" << i << endl;
    }
  }

  if (succeed) cout << "Good Job" << endl;
  else cout << "Try again" << endl;

  return 0;
}