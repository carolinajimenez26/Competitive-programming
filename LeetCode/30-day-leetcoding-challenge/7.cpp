#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  // n log n
  int countElements(vector<int>& arr) {
    // n = arr.size()
    sort(arr.begin(), arr.end()); // n log (n)
    int result = 0;
    for (int i = 0; i < arr.size(); i++) { // n
      if (IsInArray(arr, arr[i] + 1, 0, arr.size() - 1)) { // log n
        result++;
      }
    }
    return result;
  }
private:
  bool IsInArray(const vector<int>& v, int x, int left, int right) {
    while (left <= right) {
      int mid = (left + right) / 2;
      if (v[mid] == x) {
        return true;
      }
      if (v[mid] < x) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};

struct Test {
  vector<int> nums;
  int count;
};

int main(void) {
  vector<Test> tests = {
    {
      {1,2,3},
      2
    },
    {
      {1,1,3,3,5,5,7,7},
      0
    },
    {
      {1,3,2,3,5,0},
      3
    },
    {
      {1,1,2,2},
      2
    }
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int out = sol.countElements(test.nums);
    if (out != test.count) {
      succeed = false;
      cout << "Failed on test #" << tc << ". Expected " << test.count << ", got "
           << out << endl;
    }
    tc++;
  }
  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;
  return 0;
}