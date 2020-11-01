#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    if (nums.empty()) return -1; // error
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      ans ^= nums[i];
    }
    return ans;
  }
};
/*
[2,2,1] =>  
2 = (10)
2 = (10)
1 = (01)
XOR ----
     01
*/

int main(void) {
  return 0;
}