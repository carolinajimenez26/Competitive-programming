#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
using namespace std;

int MaximumOfMaximumsOfMinimums(const vector<int>& v, int partitions) {
  if (partitions == 1) {
    return *min_element(v.begin(), v.end());
  }
  if (partitions == 2) {
    return max(v[0], v.back());
  }
  return *max_element(v.begin(), v.end());
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cout << MaximumOfMaximumsOfMinimums(nums, k) << endl;
  return 0;
}