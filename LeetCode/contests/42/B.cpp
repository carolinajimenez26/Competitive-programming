#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double curr_time = 0;
    double customers_times = 0;
    for (int i = 0; i < customers.size(); i++) {
      int arrival = customers[i][0];
      if (i == 0 || arrival > curr_time) {
        curr_time = arrival;
      }
      int food_time = customers[i][1];
      curr_time += food_time;
      customers_times += (curr_time - arrival);
    }
    return customers_times / customers.size();
  }
};

struct Test {
  vector<vector<int>> customers;
  double expected;
};

int main(void) {
  vector<Test> tests = {
    { {{1,2},{2,5},{4,3}}, 5 },
    { {{5,2},{5,4},{10,3},{20,1}}, 3.25 },
    { {{20,20},{25,3},{26,1}}, 18.666 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    double out = sol.averageWaitingTime(test.customers);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}