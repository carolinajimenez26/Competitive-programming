#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool validate(vector<int>& weights, int D, int capacity) {
    int sum = 0;
    for (int i = 0; i < weights.size(); i++) {
      int w = weights[i];
      if (w > capacity) return false;
      if (D == 0) return false;
      if (sum + w <= capacity) {
        sum += w;
      } else {
        D--;
        sum = w;
      }
      if (i == weights.size() - 1 && D == 0) return false;
    }
    return true;
  }

  // int binarySearch(int lo, int hi, vector<int>& weights, int D) {
  //   int mid = lo + (hi - lo) / 2;
  //   if (hi == lo) return lo;
  //   if (validate(weights, D, mid)) {
  //     return binarySearch(lo, mid, weights, D);
  //   } else {
  //     return binarySearch(mid + 1, hi, weights, D);
  //   }
  // }

  int binarySearch(int lo, int hi, vector<int>& weights, int D) {
    int mid;
    while (lo < hi) {
      mid = lo + (hi - lo) / 2;
      if (validate(weights, D, mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }

  int shipWithinDays(vector<int>& weights, int D) {
    int total_sum = 0;
    for (auto w : weights) {
      total_sum += w;
    }
    return binarySearch(0, total_sum, weights, D);
  }
};

int main (void) {
  vector<vector<int>> weights = {
    {3,2,2,4,1,4},
    {1,2,3,4,5,6,7,8,9,10},
    {1,2,3,1,1}
  };
  vector<int> days = {
    3,
    5,
    4
  };

  vector<int> expected = {
    6,
    15,
    3
  };

  bool succeed = true;

  for (int i = 0; i < weights.size(); i++) {
    Solution sol;
    int output = sol.shipWithinDays(weights[i], days[i]);
    if (output != expected[i]) {
      succeed = false;
      cout << "Expected " << expected[i] << " , Got " << output << endl;
    }
  }

  if (succeed) cout << "Good Job" << endl;
  else cout << "Try again" << endl;

  return 0;
}