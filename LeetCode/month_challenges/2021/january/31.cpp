#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(const vector<int>& v) {
  for (auto e : v) {
    cout << e << " ";
  }
  cout << endl;
}

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int last_not_decreasing_idx = GetLastNotDecreasingIdx(nums);
    if (last_not_decreasing_idx == -1) {
      sort(nums.begin(), nums.end());
      return;
    }
    int next_greater_idx = GetNextGreaterIdx(last_not_decreasing_idx, nums);
    swap(nums[last_not_decreasing_idx], nums[next_greater_idx]);
    sort(nums.begin() + last_not_decreasing_idx + 1, nums.end());
  }
private:
  const int INF = numeric_limits<int>::max();

  int GetLastNotDecreasingIdx(const vector<int>& nums) {
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        return i;
      }
    }
    return -1;
  }

  int GetNextGreaterIdx(int target_idx, const vector<int>& nums) {
    int next_greater = INF;
    int result = target_idx;
    for (int i = target_idx + 1; i < nums.size(); i++) {
      if (nums[i] < next_greater && nums[i] > nums[target_idx]) {
        next_greater = nums[i];
        result = i;
      }
    }
    return result;
  }
};

struct Test {
  vector<int> nums;
  vector<int> expected;
};

int main (void) {
  vector<Test> tests = {
    { {4,7,5,2,1}, {5,1,2,4,7} },
    { {8,7,5,2,1}, {1,2,5,7,8} },
    { {1,3,2,4}, {1,3,4,2} },
    { {1}, {1} },
    { {}, {} },
    { {2,1}, {1,2} },
    { {1,2}, {2,1} },
    { {1,5,1}, {5,1,1} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    sol.nextPermutation(test.nums);
    if (test.nums != test.expected) {
      cout << "Failed on test #" << tc << endl;
      Print(test.nums);
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}

/*

1 2 3

1 2 3
2 1 3
3 2 1

----------------------
Generating permutations for [1 2 3 4]

1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1


5 1 2 3 4  ==> 5 1 2 4 3

6 7 1 3 2 5 4  ===> 6 7 1 3 4 2 5

7 5 2 1

8 7 5 2 1 ==> finished

4 7 5 2 1  ==> 5 1 2 4 7
*/