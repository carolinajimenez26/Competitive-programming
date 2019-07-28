#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void print(vector<int> v) {
  for (auto& e : v) cout << e << " ";
  cout << endl;
}

void print(vector<pair<int, int>> v) {
  for (int i = 0; i < v.size(); i++) {
      cout << v[i].first << "->" << v[i].second << endl;
  }
}

vector<pair<int, int>> getInfo(vector<int>& nums) {
  vector<pair<int, int>> result(nums.size());
  for (int i = 0; i < nums.size(); i++) {
    result[i] = make_pair(nums[i], i);
  }
  return result;
}

vector<int> copy(vector<pair<int,int>>& input) {
  vector<int> output(input.size());
  for (int i = 0; i < input.size(); i++)
    output[i] = input[i].second;
  return output;
}

vector<int> findDuplicates(vector<int>& nums) {
  // print(nums);
  if (nums.size() == 0) return {};
  vector<pair<int,int>> result;
  vector<pair<int, int>> nums_info = getInfo(nums);
  sort(nums_info.begin(), nums_info.end());
  // print(nums_info);
  int prev = nums_info[0].first;
  for (int i = 1; i < nums_info.size(); i++) {
    if (nums_info[i].first == prev)
      result.push_back(make_pair(nums_info[i].second, nums_info[i].first));
    prev = nums_info[i].first;
  }
  sort(result.begin(), result.end());
  return copy(result);
}

vector<int> findDuplicates2(vector<int>& nums) { // O (n)
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++) {
    int idx = nums[i] - 1;
    if ((nums[i] != (i + 1)) && (nums[i] != nums[idx]) ) {
      swap(nums[i], nums[idx]);
      i--;
    }
  }
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != (i + 1)) {
      ans.push_back(nums[i]);
    }
  }
  return ans;
}

int main(void) {
  vector<int> input = {4,3,2,7,8,2,3,1,1,1,1,1,1,2,2,2,2,3,3,3,3};
  print(findDuplicates(input));
  return 0;
}
