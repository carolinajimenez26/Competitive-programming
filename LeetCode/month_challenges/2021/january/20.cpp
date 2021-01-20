#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s_) {
    s = s_;
    idx = 0;
    char empty = 'x';
    return IsValid(empty);
  }
private:
  string s;
  int idx;
  unordered_map<char, char> matches = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'}
  };

  bool IsValid(const char last_opened) {
    if (idx >= s.size()) {
      return last_opened == 'x';
    }
    char curr = s[idx];
    if (!IsOpenning(curr)) {
      return matches[last_opened] == curr;
    }
    idx++;
    bool next = IsValid(curr);
    if (!next) {
      return false;
    }
    idx++;
    return IsValid(last_opened);
  }

  bool IsOpenning(char c) {
    return (c == '(' || c == '{' || c == '[');
  }
};

struct Test {
  string s;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    { "()[]{}", true },
    { "()[{}", false },
    { "([]{})", true },
    { "([](){})", true },
    { "(](){})", false },
    { "[(])" , false },
    { "{[]}{[]}", true },
    { "{[][]()}{[]}", true },
    { "{[][)]()}{[]}", false },
    { "{[][{})]()}{[]}", false },
    { "{[][{}]()}{[]}", true },
    { "(}", false },
    { "", true },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.isValid(test.s);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}