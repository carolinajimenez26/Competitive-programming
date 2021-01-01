#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <limits>
using namespace std;

struct State {
  int day, passes;

  bool operator<(const State& other) const {
    if (day == other.day) {
      return passes < other.passes;
    }
    return day < other.day;
  }
};

class Solution {
private:
  unordered_set<int> days_to_travel;
  vector<int> costs;
  // TODO: change map for unordered map to improve runtime access. For this, we need
  // to create a hash function for State
  map<State, int> memo;
  const int INF = numeric_limits<int>::max();

  int mincostTickets(const State& state) {
    if (state.day > 365) return 0;
    if (memo.count(state) > 0) return memo[state];

    if (days_to_travel.count(state.day) == 0) { // this is not a day I need to travel
      if (state.passes > 0) { // passes need to be use each continuous day
        return memo[state] = mincostTickets({state.day + 1, state.passes - 1});
      } 
      return memo[state] = mincostTickets({state.day + 1, state.passes});
    }
    if (state.passes > 0) { // we can use one of the passes we already bought
      return memo[state] = mincostTickets({state.day + 1, state.passes - 1});
    }

    int op1 = costs[0] + mincostTickets({state.day + 1, 0}); // we use the pass today
    int op2 = costs[1] + mincostTickets({state.day + 1, 6}); // we use one pass today, we have 6 left
    int op3 = costs[2] + mincostTickets({state.day + 1, 29}); // we use one pass today, we have 29 left

    return memo[state] = min(op1, min(op2, op3));
  }

public:
  int mincostTickets(vector<int>& days, vector<int>& _costs) {
    days_to_travel = unordered_set<int>(days.begin(), days.end());
    costs = _costs;
    return mincostTickets({1, 0});
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