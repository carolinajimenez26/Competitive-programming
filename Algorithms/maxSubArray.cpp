#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// O (nums.size())
int maxSubArrayIterative(vector<int>& nums) {
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

// O (nums.size() ^ 2)
int maxSubArraySlow(vector<int>& nums) {
  int best = -2147483648;
  if (nums.size() == 0) return best;
  int sum, best_tmp;
  for (int i = 0; i < nums.size(); i++) {
    sum = best_tmp = nums[i];
    for (int j = i + 1; j < nums.size(); j++) {
      sum += nums[j];
      best_tmp = max(best_tmp, sum);
    }
    best = max(best, best_tmp);
  }
  return best;
}

int main(void) {
  vector<int> v= {-2,1,-3,4,-1,2,1,-5,2}; // [4,-1,2,1] has the largest sum = 6.
  cout << maxSubArrayIterative(v) << endl;
  cout << maxSubArraySlow(v) << endl;
  return 0;
}