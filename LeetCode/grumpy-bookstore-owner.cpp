#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> grumpy;
  vector<int> customers;
  vector<int> customers_prefix_sum;
  vector<int> customers_grumpy_prefix_sum;
public:
  void Print(vector<int> v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }

  int GetCount(int from, int to, const vector<int>& prefix_sum) {
    if (to < from || from < 0 || to >= prefix_sum.size()) {
      return 0;
    }
    if (from == 0) {
      return prefix_sum[to];
    }
    return prefix_sum[to] - prefix_sum[from - 1];
  }

  int CountSatisfaction(int from, int to) {
    return GetCount(0, from - 1, customers_grumpy_prefix_sum) +
           GetCount(to + 1, customers_grumpy_prefix_sum.size() - 1, customers_grumpy_prefix_sum) + 
           GetCount(from, to, customers_prefix_sum); 
  }

  vector<int> CalculatePrefix(const vector<int>& v) {
    vector<int> result = v;
    for (int i = 1; i < v.size(); i++) {
      int sum = result[i - 1] + result[i];
      result[i] = sum;
    }
    return result;
  }

  vector<int> CalculatePrefix(const vector<int>& v_a, const vector<int>& v_b) {
    vector<int> result = v_a;
    if (v_b[0] == 1) result[0] = 0;
    for (int i = 1; i < v_a.size(); i++) {
      int sum = result[i - 1] + result[i];
      if (v_b[i] == 0) {
        result[i] = sum;
      } else {
        result[i] = result[i - 1];
      }
    }
    return result;
  }

  int maxSatisfied(vector<int>& customers_, vector<int>& grumpy_, int X) {
    if (customers_.empty()) {
      return 0;
    }
    customers = customers_;
    grumpy = grumpy_;

    customers_prefix_sum = CalculatePrefix(customers_);
    // Print(customers_prefix_sum);
    customers_grumpy_prefix_sum = CalculatePrefix(customers_, grumpy_);
    // Print(customers_grumpy_prefix_sum);

    int best = 0; 
    for (int i = 0; i < grumpy.size(); i++) {
      best = max(best, CountSatisfaction(i, i + X - 1));
    }
    return best;
  }
};

/*
The solution is, count what is the current clients satisfaction without the sum from the part of
the grumpy array you are changing (from i to i + X), then sum just that part like if the grumpy array
were set all to zeros in that part.

E.g:

Input:

customers            = [1,0,1,2,1,1,7,5]
grumpy               = [0,1,0,1,0,1,0,1]

Calculated prefix sums:

// this is the prefix sum if the bookstore owner were not grumpy at any time
customers_prefix_sum = [1,1,2,4,5,6,13,18]
// This is the prefix sum of the clients's satisfaction with the actual bookstore owner's behaviour 
customers_grumpy_sum = [1,1,2,2,3,3,10,10]

And let's say we want to change grumpy's array from i = 2 to i = 3: 

That would be, count how much you had in customers_grumpy_sum from i = 0 to i = 1 
plus customers_prefix_sum from i = 2 to i = 3 plus customers_grumpy_sum from i = 4 to i = 8 (to the end)
*/

int main(void) {
  vector<int> customers = {9,10,4,5};//{1,0,1,2,1,1,7,5};
  vector<int> grumpy    = {1, 0,1,1};//{0,1,0,1,0,1,0,1};
  int X = 1;//2;
  Solution sol;
  cout << sol.maxSatisfied(customers, grumpy, X) << endl;
  return 0;
}