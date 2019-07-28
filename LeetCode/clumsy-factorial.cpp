#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

void print(stack<string> st) {
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}

void print(vector<string> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

string calc(int x, string op, int y) {
  int result;
  if (op == "+") {
    result = x + y;
  }
  if (op == "-") {
    result = x - y;
  }
  if (op == "/") {
    result = x / y;
  }
  if (op == "*") {
    result = x * y;
  }

  return to_string(result);
}

stack<string> getResultWithOperands(stack<string> st1, string& op1, string& op2) {
  stack<string> st2;
  string op, x, y, z;
  while (st1.size() > 1) {
    x = st1.top();
    st1.pop();
    st2.push(x);
    op = st1.top();
    st1.pop();
    if (op == op1 || op == op2) {
      x = st2.top();
      st2.pop();
      y = st1.top();
      st1.pop();
      z = calc(stoi(x), op, stoi(y));
      st1.push(z);
    } else {
      st2.push(op);
    }
  }
  st2.push(st1.top());
  st1.pop();
  return st2;
}

stack<string> reverse(stack<string> st) {
  stack<string> result;
  while (!st.empty()) {
    result.push(st.top());
    st.pop();
  }
  return result;
}

int clumsy(int N) {
  vector<string> operands = {{"*"}, {"/"}, {"+"}, {"-"}};
  vector<string> input;
  int j = 0;
  stack<string> st;
  queue<string> q;

  for (int i = N; i >= 1; i--, j++) {
    input.push_back(to_string(i));
    if (i != 1) input.push_back(operands[j % operands.size()]);
  }
  // print(input);
  for (int i = input.size() - 1; i >= 0; i--) {
    st.push(input[i]);
  }
  st = getResultWithOperands(st, operands[0], operands[1]);
  st = reverse(st);
  st = getResultWithOperands(st, operands[2], operands[3]);
  return stoi(st.top());
}

int main(void) {
  cout << clumsy(100) << endl;
  return 0;
}
