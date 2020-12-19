#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct Range {
  int from, to;

  int GetSize() {
    return (to - from);
  }

  void KeepLower(Range other) {
    if (to < other.to) {
      from = other.from;
      to = other.to;
    }
  }
};

class Solution {
private:
  vector<int> v;

  bool IsValid(int idx) {
    return idx >= 0 && idx < v.size();
  }

  bool CanGoUp(int idx) {
    if (!IsValid(idx) || (idx + 1 >= v.size())) return false;
    return v[idx] <= v[idx + 1];
  }

  bool CanGoDown(int idx) {
    if (!IsValid(idx) || (idx + 1 >= v.size())) return false;
    return v[idx] > v[idx + 1];
  }

  Range GoUp(int from) {
    // dbg("GoUp"); dbg(from);
    if (!CanGoUp(from)) return {from, from};
    int curr = v[from];
    int i = from;
    for (; i < v.size(); i++) {
      if (v[i] < curr) break;
      curr = v[i];
    }
    return {from, i - 1};
  }

  Range GoDown(int from, Range& last) {
    // dbg("GoDown"); dbg(from);
    if (!CanGoDown(from)) return {from, from};
    int curr = v[from];
    int i = from;
    for (; i < v.size(); i++) {
      if (v[i] > curr) break;
      curr = v[i];
      if (curr > v[last.from] && curr < v[last.to]) {
        last.to = i;
      }
    }
    return {from, i - 1};
  }

  vector<int> Normalize(const vector<int>& nums) {
    vector<int> ans;
    int i = 0;
    while (i < nums.size()) {
      int curr = nums[i];
      while (i < nums.size() && nums[i] == curr) i++;
      ans.push_back(curr);
    }
    return ans;
  }

  bool Validate(Range curr, Range last) {
    if (last.GetSize() == 0) return false;
    if (!IsValid(last.to) || !IsValid(curr.to)) return false;
    return (curr.GetSize() >= 1 && v[last.to] < v[curr.to]);
  }

  void Print() {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }
public:
  bool increasingTriplet(vector<int>& nums) {
    v = Normalize(nums);
    if (v.size() <= 2) return false;
    // Print();
    int i = 0;
    Range last = {-1,-1};
    while (i < v.size()) {
      // dbg("---");
      // dbg(i);
      Range curr = GoUp(i);
      i = curr.to;
      // dbg(i);
      // dbg(curr.GetSize());
      // dbg(curr.from); dbg(curr.to); dbg(last.from); dbg(last.to);
      if (curr.GetSize() >= 2 || Validate(curr, last)) {
        return true;
      }
      last.KeepLower(curr);
      Range tmp = GoDown(i, last);
      i = tmp.to;
      // dbg(i);
      // dbg((i == v.size() - 1));
      if (i == v.size() - 1) return false;
    }
    return false;
  }
};

struct Test {
  vector<int> nums;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,2,3,4,5}, true },
    { {5,4,3,2,1}, false },
    { {2,1,5,0,4,6}, true },
    { {5,3,4,6}, true },
    { {}, false },
    { {1,1,1,1}, false },
    { {1,2}, false },
    { {1,1,1,-1,-2,-3,2}, false },
    { {1,1,2,-1,-2,-3}, false },
    { {1,1,2,-1,-2,-3,3}, true },
    { {2,1,5,0,3}, false },
    { {5,1,5,5,2,5,4}, true },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.increasingTriplet(test.nums);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}

