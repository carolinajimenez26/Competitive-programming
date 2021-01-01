#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans;
    for (auto num : nums) {
      int square = num * num;
      ans.push_back(square);
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};

int main(void) {
  return 0;
}