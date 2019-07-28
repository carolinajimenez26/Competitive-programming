#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(stack<int> s) {
  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  stack<int> s;
  int i = 0, j = 0;
  while (i < pushed.size() && j < popped.size()) {
    while (i < pushed.size() && j < popped.size() && pushed[i] != popped[j]) {
      s.push(pushed[i]);
      i++;
    }
    if (i < pushed.size()) s.push(pushed[i]);
    i++;
    while (!s.empty() && j < popped.size() && s.top() == popped[j]) {
      s.pop();
      j++;
    }
  }
  return i == pushed.size() && j == popped.size() && s.empty();
}

int main(void) {
  vector<int> pushed = {1,2,3,4,5}, popped = {4,5,3,2};
  cout << validateStackSequences(pushed, popped) << endl;
  return 0;
}
