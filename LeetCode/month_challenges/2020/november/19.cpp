#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void Print(const vector<vector<int>>& intervals) {
    for (auto interval : intervals) {
      cout << "{" << interval[0] << "," << interval[1] << "}, ";
    }
    cout << endl;
  }

  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int MAX = 10e4 + 4;
    vector<int> positives(MAX, 0);
    vector<int> negatives(MAX, 0);
    for (auto interval : intervals) {
      int from = interval[0], to = interval[1];
      positives[from] += 1;
      negatives[to + 1] -= 1;
    }
    int curr = 0;
    vector<int> tmp;
    tmp.reserve(MAX);
    for (int i = 0; i < MAX; i++) {
      // close events first 
      if (curr > 0 && (curr + negatives[i]) == 0) {
        tmp.push_back(i - 1);
      }
      curr += negatives[i];

      // open second
      if (curr == 0 && (curr + positives[i]) > 0) {
        tmp.push_back(i);
      }
      curr += positives[i];
    }
    vector<vector<int>> ans;
    for (int i = 0; i < tmp.size(); i += 2) {
      ans.push_back({ tmp[i], tmp[i + 1] });
    }
    return ans;
  }
};

struct Test {
  vector<vector<int>> intervals, expected;
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
    {
      {{0,3},{4,7},{8,11},{12,15},{5,15}},
      {{0,3},{4,15}},
    },
    {
      {{0,3},{4,7},{8,11},{12,15},{0,15}},
      {{0,15}},
    },
    {
      {{0,3},{4,7},{8,11},{12,15},{0,15},{16,20}},
      {{0,15},{16,20}},
    },
    {
      {{0,3},{4,7},{8,11},{12,15},{0,15},{16,17},{16,20}},
      {{0,15},{16,20}},
    },
    {
      {{1,4},{0,2},{3,5}},
      {{0,5}},
    },
    {
      {{4,5},{2,4},{4,6},{3,4},{0,0},{1,1},{3,5},{2,2}},
      {{0,0},{1,1},{2,6}},
    }
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<vector<int>> out = sol.merge(test.intervals);
    sort(out.begin(), out.end());
    sort(test.expected.begin(), test.expected.end());
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