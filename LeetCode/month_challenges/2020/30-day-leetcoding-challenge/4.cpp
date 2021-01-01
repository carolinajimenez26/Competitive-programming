#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int z_i = FindFirstZero(nums);
    if (z_i == -1) return;
    int i = z_i + 1;
    while (i < nums.size() && z_i <= i) {
      while (i < nums.size() && nums[i] == 0) {
        i++;
      }
      if (i >= nums.size()) {
        return;
      }
      Swap(nums, z_i, i);
      z_i++;
      i++;
    }
  }
private:
  int FindFirstZero(const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) return i;
    }
    return -1;
  }

  void Swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
};

void print(const vector<int>&v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  vector<int> v = {0,1,0,3,12};
  Solution sol;
  sol.moveZeroes(v);
  print(v);
  return 0;
}