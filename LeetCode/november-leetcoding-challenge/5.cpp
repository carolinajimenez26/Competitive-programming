#include <iostream>
#include <vector>
#include <limits>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct Result {
  bool succeed;
  int val;
};

class Solution {
private:
  Result GetElementByType(const vector<int>& v, const string& op) {
    for (auto e : v) {
      if (e % 2 == 0 && op == "even") return {true, e};
      if (e % 2 != 0 && op == "odd") return {true, e};
    }
    return {false, -1};
  }

  int MovementCount(const vector<int>& position, int fixed_pos) {
    int ans = 0;
    for (int i = 0; i < position.size(); i++) {
      if (position[i] == fixed_pos) continue;
      if (abs(position[i] - fixed_pos) % 2 != 0) {
        ans++;
      }
    }
    return ans;
  }
public:
  int minCostToMoveChips(vector<int>& position) {
    if (position.empty()) return 0;
    Result even_pos_result = GetElementByType(position, "even");
    Result odd_pos_result = GetElementByType(position, "odd");
    const int INF = numeric_limits<int>::max();
    int op1, op2;
    op1 = op2 = INF;
    if (even_pos_result.succeed) {
      op1 = MovementCount(position, even_pos_result.val);
    }
    if (odd_pos_result.succeed) {
      op2 = MovementCount(position, odd_pos_result.val);
    }
    return min(op1, op2);
  }
};

struct Test {
  vector<int> position;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,2,3}, 1 },
    { {2,2,2,3,3}, 2 },
    { {1,1000000000}, 1},
    { {0,0,0,50}, 0 },
    { {10,10}, 0 },
    { {}, 0 },
    { {11, 51, 51}, 0 },
    { {3,3,1,2,2}, 2 },
    { {0,1,1,2,3,4,8,8}, 3 },
    { {10,10,11,11,51,55,55,55,2,3}, 3 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.minCostToMoveChips(test.position);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " 
           << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}