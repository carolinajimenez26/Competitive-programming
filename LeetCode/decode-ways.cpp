#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
  vector<int> memo;

  bool CanBeDecoded(const string& s) {
    if (s.size() <= 0 || s.size() > 2) return false;
    if (s.size() > 1 && s[0] == '0') {
      return false;
    }
    int n = stoi(s);
    return n >= 1 && n <= 26;
  }

  pair<bool,int> NumDecodings(const string& s, int idx) {
    if (idx >= s.size()) {
      return {true, 1};
    }
    if (memo[idx] != -1) {
      return {true, memo[idx]};
    }
    int result = 0;
    bool op1 = false, op2 = false;
    pair<bool, int> partial;
    string curr;
    curr.push_back(s[idx]);
    op1 = CanBeDecoded(curr);
    if (op1) {
      partial = NumDecodings(s, idx + 1);
      if (partial.first) {
        result += partial.second;
      }
    }
    if (idx + 1 < s.size()) {
      curr.push_back(s[idx + 1]);
      op2 = CanBeDecoded(curr);
      if (op2) {
        partial = NumDecodings(s, idx + 2);
        if (partial.first) {
          result += partial.second;
        }
      }
    }
    memo[idx] = (op1 || op2) ? result : -1;
    return {(op1 || op2), result};
  }

public:
  int numDecodings(string s) {
    memo.assign(s.size(), -1);
    pair<bool, int> result = NumDecodings(s, 0);
    return result.second;
  }
};

/*
2265:

sol: 2 2 6 5, 22 6 5, 2 26 5

2 265
22 65
226 5
2265

265:

2 65
26 5
265

65:

6 5
65

5:

5

*/

int main(void) {
  string input = "2265";
  Solution sol;
  cout << sol.numDecodings(input) << endl;
  return 0;
}