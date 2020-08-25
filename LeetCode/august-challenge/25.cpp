#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>
using namespace std;

class Solution {
private:
  unordered_set<int> days_to_travel;
  vector<int> costs;
  vector<vector<int>> memo;
  const int INF = numeric_limits<int>::max();

  int mincostTickets(int day, int curr_pass_amount) {
    if (day > 365) return 0;
    if (memo[day][curr_pass_amount] != -1) return memo[day][curr_pass_amount];

    if (days_to_travel.count(day) == 0) { // this is not a day I need to travel
      if (curr_pass_amount > 0) { // passes need to be use each continuous day
        return memo[day][curr_pass_amount] = mincostTickets(day + 1, curr_pass_amount - 1);
      } 
      return memo[day][curr_pass_amount] = mincostTickets(day + 1, curr_pass_amount);
    }
    if (curr_pass_amount > 0) { // we can use one of the passes we already bought
      return memo[day][curr_pass_amount] = mincostTickets(day + 1, curr_pass_amount - 1);
    }

    int op1 = costs[0] + mincostTickets(day + 1, 0); // we use the pass today
    int op2 = costs[1] + mincostTickets(day + 1, 6); // we use one pass today, we have 6 left
    int op3 = costs[2] + mincostTickets(day + 1, 29); // we use one pass today, we have 29 left

    return memo[day][curr_pass_amount] = min(op1, min(op2, op3));
  }

public:
  int mincostTickets(vector<int>& days, vector<int>& _costs) {
    days_to_travel = unordered_set<int>(days.begin(), days.end());
    costs = _costs;
    memo.resize(367, vector<int>(30 * 367, -1));
    return mincostTickets(1, 0);
  }
};

struct Test {
  vector<int> days, costs;
  int ans;
};

int main(void) {
  vector<Test> tests = { 
    { {1,4,6,7,8,20}, {2,7,15}, 11 },
    { {1,2,3,4,5,6,7,8,9,10,30,31}, {2,7,15}, 17 },
    { {1,10,30}, {1,1,1}, 1},
    { {}, {1,2,3}, 0 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.mincostTickets(test.days, test.costs);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}