#include <iostream>
#include <vector>
#include <set>

using namespace std;

using Subset = vector<vector<int>>;

class Solution {
public:
  void print(set<vector<int>>& s) {
    for (auto v : s) {
      for (auto e : v) cout << e << " ";
      cout << endl;
    }
    cout << endl;
  }

  void createAllSubsets(vector<int>& nums, set<vector<int>>& result) {
    if (nums.size() == 0) return;
    for (int i = nums.size() - 1; i >= 0; i--) {
      vector<int> copy = nums;
      copy.erase(copy.begin() + i);
      if (result.count(copy) == 0) createAllSubsets(copy, result);
    }
    result.insert(nums);
    // print(result);
  }

  Subset subsets(vector<int>& nums) {
    Subset result;
    set<vector<int>> set_result;
    createAllSubsets(nums, set_result);
    for (auto v : set_result) {
      result.push_back(v);
    }
    print(set_result);
    return result;
  }
};

int main(void) {
  vector<int> input = {1,2,3,4};
  Solution sol;
  Subset result = sol.subsets(input);
  return 0;
}