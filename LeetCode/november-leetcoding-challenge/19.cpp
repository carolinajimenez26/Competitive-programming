#include <iostream>
#include <vector>
#include <set>
using namespace std;
using interval_vector = vector<vector<int>>;

class Solution {
private:
  bool Overlaps(const vector<int>& a, const vector<int>& b) {
    return max(a[0], b[0]) <= min(a[1], b[1]);
  }

  vector<int> Merge(const vector<int>& a, const vector<int>& b) {
    int left = min(a[0], b[0]);
    int right = max(a[1], b[1]);
    vector<int> new_interval = {left, right};
    return new_interval;
  }

  void RemoveAll(set<vector<int>>& from, const interval_vector& to_remove) {
    for (auto interval : to_remove) {
      from.erase(interval);
    }
  }
public:
  // where n = intervals.size()
  // Runtime: n^2
  // Spacetime: n
  interval_vector merge(interval_vector& intervals) {
    if (intervals.empty()) return {};
    set<vector<int>> ans;
    for (auto interval : intervals) { // O(n)
      int left = interval[0];
      int right = interval[1];
      interval_vector to_remove;
      for (auto interval_ans : ans) { // O(n)
        if (Overlaps(interval, interval_ans)) {
          to_remove.push_back(interval_ans);
          left = min(left, interval_ans[0]);
          right = max(right, interval_ans[1]);
        }
      }
      RemoveAll(ans, to_remove); // O(n * log n)
      ans.insert({left, right});
    }
    return interval_vector(ans.begin(), ans.end());
  }

  void Print(const interval_vector& intervals) {
    for (auto interval : intervals) {
      cout << "{" << interval[0] << "," << interval[1] << "}, ";
    }
    cout << endl;
  }
};

struct Test {
  interval_vector intervals, expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {{2,3},{4,5},{6,7},{8,9},{1,10}},
      {{1,10}},
    },
    {
      {{1,3},{6,6},{8,10},{15,18},{15,16}},
      {{1,3},{6,6},{8,10},{15,18}}
    },
    {
      {{1,3},{6,6},{8,10},{15,18},{20,20}},
      {{1,3},{6,6},{8,10},{15,18},{20,20}}
    },
    {
      {{0,20},{1,3},{6,6},{8,10},{15,18},{20,20}},
      {{0,20}}
    },
    {
      {{0,22},{1,3},{6,6},{8,10},{15,18},{20,20}},
      {{0,22}}
    },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    interval_vector out = sol.merge(test.intervals);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      cout << "Input: " << endl;
      sol.Print(test.intervals);
      cout << "Found: " << endl;
      sol.Print(out);
      cout << "Expected: " << endl;
      sol.Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}