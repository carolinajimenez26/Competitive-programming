#include <iostream>
#include <vector>
#include <limits>
#define INF numeric_limits<int>::max()

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return -2147483648;
    int best = nums[0];
    int curr = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int sum = curr + nums[i];
      curr = max(sum, nums[i]);
      best = max(curr, best);
    }
    return best;
  }
};

int main(void) {
  vector<int> v= {-2,1,-3 }; // [4,-1,2,1] has the largest sum = 6.
  Solution sol;
  cout << sol.maxSubArray(v) << endl;
  return 0;
}