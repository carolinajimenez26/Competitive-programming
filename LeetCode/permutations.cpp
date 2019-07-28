#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> result;
  sort(nums.begin(), nums.end());
  do {
    vector<int> perm = nums;
    result.push_back(nums);
  } while(next_permutation(nums.begin(), nums.end()));
  sort(result.begin(), result.end());
  return result;
}

int main(void) {
  return 0;
}
