#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
private:
  vector<int> rotateLeft(const vector<int>& code) {
    vector<int> ans = code;
    ans[code.size() - 1] = code[0];
    for (int i = 1; i < code.size(); i++) {
      ans[i - 1] = code[i];
    }
    return ans;
  }

  vector<int> rotateRight(const vector<int>& code) {
    vector<int> ans = code;
    ans[0] = code[code.size() - 1];
    for (int i = 0; i < code.size() - 1; i++) {
      ans[i + 1] = code[i];
    }
    return ans;
  }
public:
  void Print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }

  vector<int> decrypt(vector<int>& code, int k) {
    if (code.empty()) return {};
    int size = code.size();
    vector<int> copy = code;
    if (k == 0) {
      for (int i = 0; i < size; i++) {
        code[i] = 0;
      }
      return code;
    }
    for (int i = 0; i < size; i++) {
      int sum = 0;
      for (int j = 0; j < abs(k); j++) {
        int x = i + (k > 0 ? j : -j);
        if (x < 0) x += size;
        sum += copy[x % size];
      }
      code[i] = sum;
    }
    code = k > 0 ? rotateLeft(code) : rotateRight(code);
    return code;
  }
};

struct Test {
  vector<int> code;
  int k;
  vector<int> expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {5,7,1,4}, 3, {12,10,16,13}
    },
    {
      {1,2,3,4}, 0, {0,0,0,0}
    },
    {
      {2,4,9,3}, -2, {12,5,6,13}
    },
    {
      {}, 8, {}
    },
    {
      {0,0,0}, 7, {0,0,0}
    },
    {
      {1,1,1}, 1, {1,1,1}
    },
    {
      {1,1,1}, -1, {1,1,1}
    }
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.decrypt(test.code, test.k);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      sol.Print(out); sol.Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}