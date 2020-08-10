#include <iostream>
#include <vector>
using namespace std;

enum State {
  COOLDOWN,
  BUYING,
  SOLD
};

class Solution {
private:
  vector<vector<int>> memo;
  vector<int> prices;

  int maxProfit(int idx, State state) {
    if (idx >= prices.size()) {
      return 0;
    }
    if (memo[idx][state] != -1) return memo[idx][state];
    if (state == COOLDOWN) {
      return maxProfit(idx + 1, SOLD);
    }
    int op1, op2;
    if (state == SOLD) {
      op1 = maxProfit(idx + 1, SOLD); // do not buy here, try sometime else
      op2 = -prices[idx] + maxProfit(idx + 1, BUYING); // buy here
    }
    if (state == BUYING) {
      op1 = maxProfit(idx + 1, BUYING); // do not sell here, keep looking
      op2 = prices[idx] + maxProfit(idx + 1, COOLDOWN); // sell here
    }
    memo[idx][state] = max(op1, op2);
    return memo[idx][state];
  }

public:
  int maxProfit(vector<int>& in) {
    memo = vector<vector<int>>(in.size(), vector<int>(3, -1));
    prices = in;
    return maxProfit(0, SOLD);
  }
};

struct Test {
  vector<int> prices;
  int ans;
};

int main(void) {
  vector<Test> tests = {
    { {1,2,3,0,2}, 3 },
    { {1,3,3,5,5,3,1,0}, 4 },
    { {1,2,3,2,1,0}, 2 },
    { {1,2,3,0,2,0,3}, 5 },
    { {1}, 0 },
    { {1,2}, 1 },
    { {2,1}, 0 },
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int out = sol.maxProfit(test.prices);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}