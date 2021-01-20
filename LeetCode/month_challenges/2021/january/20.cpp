#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> opened;
    for (auto c : s) {
      if (IsOpenning(c)) {
        opened.push(c);
      } else {
        if (opened.empty() || !Match(opened.top(), c)) {
          return false;
        }
        opened.pop();
      }
    }
    return opened.empty();
  }
private:
  bool IsOpenning(char c) {
    return (c == '(' || c == '{' || c == '[');
  }

  bool Match(char opening, char closing) {
    if (closing == ')') {
      return opening == '(';
    }
    if (closing == '}') {
      return opening == '{';
    }
    return opening == '[';
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