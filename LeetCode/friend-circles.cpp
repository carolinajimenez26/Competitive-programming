#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> M;
  vector<bool> visited;
public:
  void DFS(int i) {
    visited[i] = true;
    for (int j = 0; j < M[0].size(); j++) { // neighs
      if (M[i][j] == 0) { // the're not friends
        continue;
      }
      if (!visited[j]) {
        DFS(j);
      }
    }
  }

  int findCircleNum(vector<vector<int>>& M_) {
    M = M_;
    visited.assign(M_.size(), false);
    int result = 0;
    for (int i = 0; i < M.size(); i++) { // every node = every person
      if (!visited[i]) {
        DFS(i);
        result++;
      }
    }
    return result;
  }
};

struct Test {
  vector<vector<int>> friends;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {{1,1,0,0}, {1,1,1,0}, {0,1,1,1}, {0,0,1,1}},
      1
    },
    {
      {{1,1,0}, {1,1,1}, {0,1,1}},
      1
    },
    {
      {{1,1,0}, {1,1,0}, {0,0,1}},
      2
    }
  };

  bool succeed = true;

  int test_case = 0;
  for (auto test : tests) {
    Solution sol;
    int out = sol.findCircleNum(test.friends);
    if (out != test.expected) {
      cout << "Failed on test #" << test_case << endl;
      succeed = false;
    }
    test_case++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;
  
  return 0;
}