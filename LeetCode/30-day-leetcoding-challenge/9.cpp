#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string S, string T) {
    S = Convert(S);
    T = Convert(T);
    return S == T;
  }
private:
  // Time complexity: O (n)
  // Space complexity: O(n)
  string Convert(string s) {
    stack<char> st;
    for (auto c : s) {
      if (c == '#') {
        if (!st.empty()) {
          st.pop();
        }
      } else {
        st.push(c);
      }
    }
    string result = "";
    while (!st.empty()) {
      result.push_back(st.top());
      st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main(void) {
  string S = "ab#c";
  string T = "ad#c";
  Solution sol;
  cout << sol.backspaceCompare(S, T) << endl;
  return 0;
}