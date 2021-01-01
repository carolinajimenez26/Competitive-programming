#include <iostream>
#include <stack>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

class MinStack {
private:
  vector<stack<int>> status;
  stack<int> min_indexes;
  int status_idx;
public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (status.size() == 0) {
      stack<int> st;
      st.push(x); // first element, this is the min
      min_indexes.push(0); // push the index of the stack where is located our min
      status_idx = 0; // last stack is the one we have to do pop
      status.push_back(st); // first stack
      return;
    }
    if (x <= getMin() && top() != getMin()) {
      // create a new stack for the new min
      stack<int> st;
      st.push(x);
      status.push_back(st);
      status_idx++;
      min_indexes.push(status_idx); // new min
      return;
    }
    if (top() == getMin() && x > getMin()) {
      stack<int> st;
      st.push(x);
      status.push_back(st);
      status_idx++;
    } else {
      status[status_idx].push(x);
    }
  }

  void pop() {
    if (status[status_idx].empty()) return; // just happens if we end up with one stack and 0 elements on it
    status[status_idx].pop();
    if (status[status_idx].empty()) {
      status.pop_back();
      if (min_indexes.top() == status_idx) {
        min_indexes.pop();
      }
      status_idx--;
    }
  }

  int top() {
    return status[status_idx].top();
  }

  int getMin() {
    int min_idx = min_indexes.top();
    return status[min_idx].top();
  }

  void print(stack<int> st) {
    while (!st.empty()) {
      cout << st.top() << " ";
      st.pop();
    }
    cout << endl;
  }

  void print() {
    cout << "---------------" << endl;
    cout << "Status: " << endl;
    for (auto st : status) {
      print(st);
    }
    cout << "Status idx " << status_idx << endl;
    cout << "Min indexes: " << endl;
    print(min_indexes);
    cout << "---------------" << endl;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(void) {
  int x;
  MinStack* obj = new MinStack();
  obj->push(0);
  obj->push(1);
  obj->print();
  obj->push(3);
  obj->push(2);
  obj->push(4);
  obj->print();
  x = obj->top();
  if (x != 4) {
    cout << "Failed: " << x << endl;
    return 0;
  }
  obj->pop();
  obj->print();
  x = obj->getMin();
  obj->print();
  if (x != 0) {
    cout << "Failed: " << x << endl;
    return 0;
  }
  obj->push(-1);
  x = obj->getMin();
  if (x != -1) {
    cout << "Failed" << endl;
    return 0;
  }
  obj->push(-2);
  obj->push(-4);
  obj->push(8);
  x = obj->top();
  if (x != 8) {
    cout << "Failed" << endl;
    return 0;
  }
  x = obj->getMin();
  if (x != -4) {
    cout << "Failed" << endl;
    return 0;
  }
  obj->pop();
  x = obj->getMin();
  if (x != -4) {
    cout << "Failed" << endl;
    return 0;
  }
  obj->pop();
  obj->pop();
  obj->pop();
  obj->print();
  x = obj->getMin();
  if (x != 0) {
    cout << "Failed" << endl;
    return 0;
  }
  x = obj->top();
  if (x != 2) {
    cout << "Failed" << endl;
    return 0;
  }
  obj->pop();
  obj->pop();
  obj->pop();
  obj->print();
  x = obj->top();
  if (x != 0) {
    cout << "Failed" << endl;
    return 0;
  }
  x = obj->getMin();
  if (x != 0) {
    cout << "Failed" << endl;
    return 0;
  }

  cout << "Congrats!" << endl;
  return 0;
}