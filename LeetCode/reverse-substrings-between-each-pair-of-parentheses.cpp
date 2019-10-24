#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

class Solution {
public:
  void Reverse(string& s, int from, int to) {
    while (from < to) {
      swap(s[from], s[to]);
      from++;
      to--;
    }
  }

  vector<pair<int, int>> FindAllParenthesesPositions(const string& s) {
    vector<pair<int,int>> result;
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(i);
      }
      if (s[i] == ')') {
        result.push_back({st.top(),i});
        st.pop();
      }
    }
    return result;
  }

  string reverseParentheses(string s) {
    vector<pair<int, int>> paren_pos = FindAllParenthesesPositions(s);
    for (auto pos : paren_pos) {
      Reverse(s, pos.first + 1, pos.second - 1);
    }

    // Remove every parentheses
    string result;
    for (auto c : s) {
      if (c != '(' && c != ')') {
        result.push_back(c);
      }
    }
    return result;
  }
};

struct Test {
  string s;
  string expected;
};

int main(void) {
  vector<Test> tests = {
    {
      "f(ul)ao(t(y)qbn)()sj",
      "fluaonbqytsj"
    },
    {
      "ta()usw((((a))))",
      "tauswa"
    },
    {
      "(ed(et(oc))el)",
      "leetcode"
    },
    {
      "(u(love)i)",
      "iloveu"
    }
  };

  bool succeed = true;

  int test_case = 0;
  for (auto test : tests) {
    Solution sol;
    string out = sol.reverseParentheses(test.s);
    if (out != test.expected) {
      cout << "Failed on test #" << test_case << endl;
      succeed = false;
    }
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}