#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
  int max_profit = 0;

  for (int i = 0; i < prices.size(); i++) {
    for (int j = i + 1; j < prices.size(); j++) {
      if (prices[j] - prices[i] > max_profit) {
        max_profit = prices[j] - prices[i];
      }
    }
  }
  return max_profit;
}

int main(void) {
  vector<int> input = {7,1,1,0,1,0};
  cout << maxProfit(input) << endl;
  return 0;
}
