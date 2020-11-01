#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
private:
  int inf = numeric_limits<int>::max();

  int FindFirstValley(const vector<int>& v, int from) {
    for (int i = from; i < v.size(); i++) {
      int before = i - 1 < 0 ? inf : v[i - 1];
      int curr = v[i];
      int after = i + 1 >= v.size() ? inf : v[i + 1];
      if (before >= curr && curr <= after) {
        return i;
      }
    }
    return v.size();
  }

  int FindFirstPeak(const vector<int>& v, int from) {
    for (int i = from; i < v.size(); i++) {
      int before = i - 1 < 0 ? -inf : v[i - 1];
      int curr = v[i];
      int after = i + 1 >= v.size() ? -inf : v[i + 1];
      if (before <= curr && curr >= after) {
        return i;
      }
    }
    return v.size();
  }
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty() || prices.size() == 1) return 0;
    int ans = 0;
    int i = 0;
    while (true) {
      i = FindFirstValley(prices, i);
      if (i >= prices.size()) break;
      int j = FindFirstPeak(prices, i + 1);
      if (j >= prices.size()) {
        ans += (prices[j - 1] - prices[i]);
        break;
      }
      ans += (prices[j] - prices[i]);
      i = j + 1;
    }
    return ans; 
  }
};

struct Test {
  vector<int> nums;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {7,1,5,3,6,4}, 7
    },
    {
      {1,2,3,4,5}, 4
    },
    {
      {7,6,4,3,1}, 0
    },
    {
      {7}, 0
    },
    {
      {7,6}, 0
    },
    {
      {7,8}, 1
    },
    {
      {7,6,8}, 2
    },
    {
      {1,1,2,3,4,5}, 4
    },
    {
      {1,2,3,4,5,5}, 4
    },
  };
  bool succeed = true;
  int tc = 0;
  for (auto test : tests) {
    Solution sol;
    int out = sol.maxProfit(test.nums);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found: " << out << ", expected: " 
           << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good Job" : "Keep trying") << endl;
  return 0;
}