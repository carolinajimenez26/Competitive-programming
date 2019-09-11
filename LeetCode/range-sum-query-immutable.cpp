#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
class NumArray {
public:
  vector<int> acc;

  NumArray(vector<int>& nums) {
    acc.resize(nums.size() + 0);
    partial_sum(nums.begin(), nums.end(), acc.begin());
  }
  
  int sumRange(int i, int j) {
    if (i - 1 >= 0) {
      return acc[j] - acc[i - 1];
    }
    return acc[j];
  }
};

/*
Given nums = [-2, 0, 3, -5, 2, -1]
             [-2,-2, 1, -4,-2, -3]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

*/
int main(void) {
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray* obj = new NumArray(nums);
  int i = 2, j = 5;
  cout << obj->sumRange(i,j) << endl;
  return 0;
}
