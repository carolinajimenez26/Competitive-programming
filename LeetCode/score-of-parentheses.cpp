#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int result[60][60];

int insertNextOrgetTop(stack<int>& st, const string& S, const int& index) {
  int result = -1;
  if (S[index] == '(') {
    st.push(index);
  } else {
    result = st.top();
    st.pop();
  }
  return result;
}

int calc(int left, int right, const string& S) {

   if (left > right) return 1;
   int count = 0;
   stack<int> st;
   while (left < right) {
     st.push(left);
     int top;
     while (!st.empty()) {
       top = insertNextOrgetTop(st, S, left + 1);
       left++;
     }
     count += result[top][left];
     left++;
   }
   return 2 * count;
}

int scoreOfParentheses(string S) {
  memset(result, -1, sizeof result);
  stack<int> st;
  st.push(0); // is always (
  int curr_index = 1;
  int top;
  while (curr_index < S.size()) {
    if (st.empty()) {
      st.push(curr_index);
      curr_index++;
    }
    while (!st.empty()) {
      top = insertNextOrgetTop(st, S, curr_index);
      if (top != -1) {
        result[top][curr_index] = calc(top + 1, curr_index - 1, S);
      }
      curr_index++;
    }
  }
  if (result[0][S.size() - 1] == -1) {
    result[0][S.size() - 1] = (calc(0, S.size() - 1, S) / 2);
  }
  return result[0][S.size() - 1];
}

int main(void) {
  cout << scoreOfParentheses("(()(()))()") << endl;
  return 0;
}
