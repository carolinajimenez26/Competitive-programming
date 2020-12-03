#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

class Solution {
private:
  vector<int> initial;
  set<vector<int>> perms;
  unordered_set<int> indexes_used;

  void Generate(vector<int>& curr) {
    if (curr.size() == initial.size()) {
      // Print(curr);
      perms.insert(curr);
      return;
    }
    for (int i = 0; i < initial.size(); i++) {
      if (indexes_used.count(i) != 0) {
        continue;
      }
      curr.push_back(initial[i]);
      indexes_used.insert(i);
      Generate(curr);
      curr.pop_back();
      indexes_used.erase(i);
    }
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    initial = nums;
    vector<int> curr;
    Generate(curr);
    vector<vector<int>> ans;
    for (auto v : perms) {
      ans.push_back(v);
    }
    return ans;
  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {1,2,3};
  sol.permuteUnique(nums);
  return 0;
}