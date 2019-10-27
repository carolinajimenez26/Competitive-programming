#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;
  int k;
public:
  void combinationSum3(vector<int> curr_sol, int n, int idx) {
    if (curr_sol.size() > k || n < 0) {
      return;
    }
    if (n == 0) {
      if (curr_sol.size() == k) {
        result.push_back(curr_sol);
      }
      return;
    }
    for (int i = idx; i <= 9 && i <= n; i++) {
      curr_sol.push_back(i);
      combinationSum3(curr_sol, n - i, i + 1);
      curr_sol.pop_back();
    }
  }

  vector<vector<int>> combinationSum3(int k_, int n) {
    k = k_;
    vector<int> curr_sol;
    combinationSum3(curr_sol, n, 1);
    return result;
  }
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void Print(const vector<vector<int>>& vvi) {
  for (auto v : vvi) {
    Print(v);
  }
}

int main(void) {
  Solution sol;
  int k = 3; 
  int n = 9;
  vector<vector<int>> result = sol.combinationSum3(k,n);
  Print(result);
  return 0;
}