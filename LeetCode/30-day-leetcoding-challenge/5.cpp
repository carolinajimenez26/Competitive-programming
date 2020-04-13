#include <iostream>
#include <vector>
#include <limits>
#define INF numeric_limits<int>::max()

using namespace std;

enum State {
  OPEN,
  CLOSED
};

using int64 = long long int;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    vector<vector<int64>> memo(prices.size(), vector<int64>(2, -1));
    return maxProfit(prices, 0, CLOSED, memo);
  }

  // O (prices.size() ^ 2)
  int maxProfitSlow(vector<int>& prices) {
    vector<int> memo(prices.size(), -1);
    return maxProfit(prices, 0, memo);
  }
private:
  int maxProfit(const vector<int>& prices, int i, vector<int>& memo) {
    if (i >= prices.size()) return 0;
    if (memo[i] != -1) return memo[i];
    int op1 = maxProfit(prices, i + 1, memo); // not buying
    int best = 0;
    for (int j = i + 1; j < prices.size(); j++) {
      int curr = prices[j] - prices[i] + maxProfit(prices, j + 1, memo);
      best = max(best, curr);
    }
    memo[i] = max(best, op1);
    return memo[i];
  }

  int64 maxProfit(const vector<int>& prices, int i, State st,
                vector<vector<int64>>& memo) {
    if (i >= prices.size()) {
      return st == OPEN ? -INF : 0;
    }
    if (memo[i][st] != -1) return memo[i][st];
    int64 op1, op2;
    if (st == OPEN) { // looking the best time to sell what I bought before
      // selling what I bought before plus starting a new buy/sell somewhere
      op1 = prices[i] + maxProfit(prices, i + 1, CLOSED, memo);
      op2 = maxProfit(prices, i + 1, OPEN, memo); // Do not sell here
    } else { // looking the best time to buy
    // buy here and look when to sell in the future
      op1 = -prices[i] + maxProfit(prices, i + 1, OPEN, memo);
      op2 = maxProfit(prices, i + 1, CLOSED, memo); // Do not buy yet
    }
    memo[i][st] = max(op1,op2);
    return memo[i][st];
  }
};

struct Test {
  vector<int> nums;
  int profit;
};

int main(void) {
  vector<Test> tests = {
    {
      {7,1,5,3,6,4},
      7
    },
    {
      {1,2,3,4,5},
      4
    },
    {
      {7,6,4,3,1},
      0
    }
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int out = sol.maxProfit(test.nums);
    if (out != test.profit) {
      succeed = false;
      cout << "Failed on test #" << tc << ". Expected " << test.profit << ", got "
           << out << endl;
    }
    tc++;
  }
  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;
  return 0;
}