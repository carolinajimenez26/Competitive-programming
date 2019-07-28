#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void print(vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }

  int DFS(vector<int>& nums, vector<bool>& visited, int i) {
    visited[i] = true;
    if (!visited[nums[i]]) {
      return 1 + DFS(nums, visited, nums[i]);
    }
    return 1;
  }

  int ArrayNesting(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    vector<bool> visited(nums.size(), false);
    vector<int> cycles;
    for (int i = 0; i < nums.size(); i++) {
      if (!visited[i]) {
        cycles.push_back(DFS(nums, visited, i));
      }
    }
    // print(cycles);
    return *max_element(cycles.begin(), cycles.end());
  }
};

int main(void) {
  vector<int> input = {5,4,0,3,1,6,2};
  Solution sol;
  cout << sol.ArrayNesting(input) << endl;
}