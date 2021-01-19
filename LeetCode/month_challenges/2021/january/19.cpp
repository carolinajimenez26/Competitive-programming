#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

template <class T>
void Print(const T& v) {
  for (auto e : v) cout << e << " ";
  cout << endl; 
}

struct Range {
  int from, to;

  int GetLenght() {
    return to - from + 1;
  }
};

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.empty()) {
      return "";
    }
    memo = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
    int best = 1;
    Range best_range = {0,0};
    for (int i = 0; i < s.size(); i++) {
      Range op = FindLongestPalindromeStarting(i, s);
      if (best < op.GetLenght()) {
        best = op.GetLenght();
        best_range = op;
      }
    }
    return s.substr(best_range.from, best_range.GetLenght());
  }
private:
  vector<vector<int>> memo;

  bool IsPalindome(const string& s, int left, int right) {
    if ((left == right) || (right < left)) {
      return true;
    }
    if (s[left] != s[right]) {
      return false;
    }
    if (memo[left][right] != -1) {
      return memo[left][right];
    }
    bool ans = IsPalindome(s, left + 1, right - 1);
    memo[left][right] = ans;
    return ans;
  }

  Range FindLongestPalindromeStarting(int from, const string& s) {
    Range best_range = {from, from};
    for (int i = from; i < s.size(); i++) {
      Range range = {from, i};
      if (IsPalindome(s, range.from, range.to)) {
        best_range = range;
      }
    }
    return best_range;
  }
};

struct Test {
  string s;
  vector<string> expected;
};

int main(void) {
  vector<Test> tests = {
    { "babad", {"bab", "aba"} },
    { "cbbd", {"bb"} },
    { "a", {"a"} },
    { "ac", {"a","c"} },
    { "babbbad", {"abbba"} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    string out = sol.longestPalindrome(test.s);
    unordered_set<string> expected(test.expected.begin(), test.expected.end());
    if (expected.count(out) == 0) {
      cout << "Failed on test #" << tc << endl; 
      Print(out);
      Print(expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}