#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(1)
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

// Time complexity: O(n log n)
// Space complexity: O(n)
int maxProfit2(vector<int>& prices) {
  if (prices.size() == 0) return 0;
  int last = prices.size() - 1;
  
  multiset<int> elems;
  // log n
  for (int i = last; i >= 0; i--) {
    elems.insert(prices[i]);
  }

  int best = 0;
  for (int i = last; i >= 1; i--) { // n
    int curr = prices[i];
    auto it = elems.find(curr); // log n
    elems.erase(it);
    int min_n = *elems.begin();
    if (curr - min_n > best) {
      best = curr - min_n;
    }
  }
  return best;
}

int main(void) {
  vector<int> input = {7,1,1,0,1,0};
  cout << maxProfit(input) << endl;
  return 0;
}
