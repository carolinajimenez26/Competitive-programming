#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  bool checkValidString(string s) {
    stack<int> opening, ast;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        opening.push(i);
      }
      if (s[i] == '*') {
        ast.push(i);
      }
      if (s[i] == ')') {
        if (!opening.empty()) {
          opening.pop();
        } else {
          if (ast.empty()) return false;
          ast.pop();
        }
      }
    }
    while (!opening.empty()) {
      if (ast.empty()) return false;
      if (opening.top() > ast.top()) {
        return false;
      }
      opening.pop();
      ast.pop();
    }
    return true;
  }
};

int main(void) {
  return 0;
}