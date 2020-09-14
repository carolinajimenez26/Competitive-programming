#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  bool IsRepeatedSubstring(const string& s, const string& subs) {
    if (subs.size() == s.size()) return false;
    int j = 0;
    for (int i = 0; i < s.size(); i++, j++) {
      if (s[i] != subs[j % subs.size()]) return false;
    }
    return (j % subs.size() == 0);
  }

  bool IsRepeatedSubstring(const string& s, const int to) {
    if (to == 0) return false;
    int j = 0;
    for (int i = 0; i < s.size(); i++, j++) {
      if (s[i] != s[j % to]) return false;
    }
    return (j % to == 0);
  }
public:
  bool repeatedSubstringPatternSlow(string s) {
    if (s.empty()) return true;
    string subs = "";
    for (auto letter : s) {
      subs.push_back(letter);
      if (IsRepeatedSubstring(s, subs)) return true;
    }
    return false;
  }

  bool repeatedSubstringPattern(string s) {
    if (s.empty()) return true;
    int x = 2;
    int size = s.size();
    while (size >= 1) {
      size = s.size() / x;
      x++;
      // substring is going to be from 0 to size
      if (IsRepeatedSubstring(s, size)) return true;
    }
    return false;
  }
};

struct Test {
  string s;
  bool ans;
};

int main(void) {
  vector<Test> tests = {
    { "abab", true },
    { "ababc", false },
    { "aba", false },
    { "abcabcabcabcd", false },
    { "", true },
    { "abcabc", true },
    { "aabbcc", false },
    { "aabbaabb", true },
    { "aabbccaadd", false },
    { "babbabbabbabbab", true },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.repeatedSubstringPattern(test.s);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}