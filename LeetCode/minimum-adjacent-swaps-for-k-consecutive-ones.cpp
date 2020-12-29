#include <iostream>
#include <vector>
#include <limits>
#include <limits>
#include <deque>
#include <algorithm>
using namespace std;
using int64 = long long int;
const int INF = numeric_limits<int>::max();

template <class T>
void Print(T v) {
  for (auto e : v) {
    if (e == INF) cout << "x" << " ";
    else cout << e << " ";
  }
  cout << endl;
}

class Solution {
public:
  int minMoves(vector<int>& nums, int k) {
    // Print(nums);
    if (k <= 1) return 0;
    vector<int> min_moves_left = CalculateMinMoves(nums, k / 2);
    reverse(nums.begin(), nums.end());
    vector<int> min_moves_right = CalculateMinMoves(nums, k - (k / 2));
    reverse(min_moves_right.begin(), min_moves_right.end());
    // Print(min_moves_left); Print(min_moves_right);
    int64 best = INF;
    for (int i = 0; i < nums.size() - 1; i++) {
      int64 sum = (int64)min_moves_left[i] + min_moves_right[i + 1];
      best = min(best, sum);
    }
    return best;
  }

  vector<int> CalculateMinMoves(vector<int>& nums, int k) {
    vector<int> ans(nums.size(), INF);
    deque<int> ones_pos; // max k size
    int i = 0;
    while (ones_pos.size() < k && i < nums.size()) {
      if (nums[i] == 1) ones_pos.push_back(i);
      i++;
    }
    i--;
    if (i >= nums.size()) {
      return ans;
    }
    ans[i] = MinMovesForIdx(k, i, ones_pos);
    i++;
    for (; i < nums.size(); i++) {
      if (nums[i] == 0) {
        ans[i] = ans[i - 1] + k;
      } else {
        int to = i - 1 - (k - 1);
        int from = ones_pos.front();
        ans[i] = ans[i - 1] - (to - from);
        ones_pos.pop_front();
        ones_pos.push_back(i);
      }
    }
    return ans;   
  }
private:
  int MinMovesForIdx(int k, int idx, deque<int> ones_pos) {
    int ans = 0;
    if (ones_pos.size() < k) return INF;
    for (int i = 0; i < k; i++) {
      ans += (idx - ones_pos.back() - i);
      ones_pos.pop_back();
    }
    return ans;
  }
};

bool RunTestsCalculateMinMoves() {
  struct Test {
    vector<int> nums;
    int k;
    vector<int> expected;
  };
  vector<Test> tests = {
    { {1,0,1}, 2, {INF, INF, 1} },
    { {1,1,0,0,1}, 3, {INF, INF, INF, INF, 4} },
    { {1}, 3, {INF} },
    { {1,0}, 1, {0,1} },
    { {1,0,0}, 1, {0,1,2} },
    { {1,0,0,1,1,0,0,1}, 3, {INF, INF, INF, INF, 2, 5, 8, 4} },
    { {1,0,0,1,1,0,0,1,0}, 3, {INF, INF, INF, INF, 2, 5, 8, 4, 7} },
    { {1,1,0,0,1}, 2, {INF, 0, 2, 4, 2} },
    { {1,1,0,0,1,1}, 2, {INF, 0, 2, 4, 2, 0} },
    { {1,1,0,0,1,1,0}, 2, {INF, 0, 2, 4, 2, 0, 2} },
    { {1,1,0,1,1,0,0,0,1,1,0}, 3, {INF, INF, INF, 2, 1, 4, 7, 10, 6, 3, 6} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.CalculateMinMoves(test.nums, test.k);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl; 
      Print(out);
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  return succeed;
}

bool RunTestsMinMoves() {
  struct Test {
    vector<int> nums;
    int k, expected;
  };

  vector<Test> tests = {
    { {1,0,0,1,0,1}, 2, 1 },
    { {1,0,0,0,0,0,1,1}, 3, 5 },
    { {1,1,0,1}, 2, 0 },
    { {0,1,1,0,0,1,0,0,0}, 3, 2 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.minMoves(test.nums, test.k);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " 
           << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  return succeed;
}

int main(void) {
  bool succeed = true;
  succeed = RunTestsCalculateMinMoves() && RunTestsMinMoves();
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}