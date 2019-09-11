#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairsHelper(const vector<int>& cost, int curr_index, vector<int>& memo) {
    int last = cost.size() - 1;
    if (curr_index == last) {
      return cost[last];
    }
    if (curr_index > last) {
      return 0; // inf, this is invalid
    }
    if (memo[curr_index] != -1) {
      return memo[curr_index];
    }
    int result = 0;
    int a = minCostClimbingStairsHelper(cost, curr_index + 1, memo); // climb 1
    int b = minCostClimbingStairsHelper(cost, curr_index + 2, memo); // climb 2
    memo[curr_index] = cost[curr_index] + min(a, b);
    return memo[curr_index];
  }

  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> memo(cost.size(), -1);
    int a = minCostClimbingStairsHelper(cost, 0, memo);
    int b = minCostClimbingStairsHelper(cost, 1, memo);
    return min(a, b);
  }
};

/*
                     1, i = 0
          101                  2, i = 2
    102        102        3, i = 3         3, i = 4
                       4, i = 4 
*/
int main(void) {
  Solution sol;
  vector<int> input = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  cout << sol.minCostClimbingStairs(input) << endl;
  return 0;
}
