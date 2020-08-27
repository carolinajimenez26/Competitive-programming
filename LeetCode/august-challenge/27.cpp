#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

struct Interval {
  int start, end;

  bool operator<(const Interval& other) const {
    if (start != other.start) return start < other.start;
    return end < other.end;
  }

  void Print() {
    cout << "[" << start << ", " << end << "]";
  }
};

class Solution {
private:
  vector<Interval> intervals;

  Interval BinarySearch(int target) {
    int left = 0, right = intervals.size() - 1;
    if (intervals[right].start < target) return {-1,-1};
    while (left < right) {
      int mid = (left + right) / 2;
      if (intervals[mid].start == target) return intervals[mid];
      if (intervals[mid].start < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return intervals[left];
  }

  void Print() {
    for (auto interval : intervals) {
      interval.Print();
      cout << ", ";
    }
    cout << endl;
  }

public:
  vector<int> findRightInterval(vector<vector<int>>& in) {
    for (auto interval : in) intervals.push_back({ interval[0], interval[1] });

    map<Interval, int> original_positions;
    for (int i = 0; i < intervals.size(); i++) {
      original_positions[intervals[i]] = i;
    }

    sort(intervals.begin(), intervals.end());
    // Print();
    
    vector<int> ans;
    for (auto elem : in) {
      Interval interval = {elem[0], elem[1]};
      Interval right_interval = BinarySearch(interval.end);
      if (original_positions.count(right_interval) == 0) {
        ans.push_back(-1);
      } else {
        ans.push_back(original_positions[right_interval]);
      }
    }

    return ans;
  }
};

struct Test {
  vector<vector<int>> in;
  vector<int> ans;
};

void Print(const vector<int>& vi) {
  for (auto i : vi) cout << i << ", ";
  cout << endl;
}

int main(void) {
  vector<Test> tests = { // you should define your Test structure
    { {{1,2}}, {-1} },
    { {{3,4}, {2,3}, {1,2}}, {-1, 0, 1} }, 
    { {{1,4}, {2,3}, {3,4}}, {-1, 2, -1} },
    { {}, {} },
    { {{1,4}, {2,3}}, {-1, -1} },
    { {{1,2},{2,3}}, {1, -1} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.findRightInterval(test.in);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found: " << endl;
      Print(out); 
      cout << "Expected: " << endl;
      Print(test.ans);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}