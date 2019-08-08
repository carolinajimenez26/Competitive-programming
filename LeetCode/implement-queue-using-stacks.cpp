#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
  stack<int> st1;
  stack<int> st2;
public:
  /** Initialize your data structure here. */
  MyQueue() {}
  
  /** Push element x to the back of queue. */
  void push(int x) {
    st1.push(x);
  }
  
  void PushAllElementsFromTo(stack<int>& s1, stack<int>& s2) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (st1.size() == 0) {
      return -1;
    }
    PushAllElementsFromTo(st1, st2);
    int elem = st2.top();
    st2.pop();
    PushAllElementsFromTo(st2, st1);
    return elem;
  }

  int GetFirstElem(stack<int> s) {
    while (s.size() > 1) {
      s.pop();
    }
    return s.top();
  }
  
  /** Get the front element. */
  int peek() {
    if (st1.size() == 0) {
      return -1;
    }
    return GetFirstElem(st1);
  }
  
  /** Returns whether the queue is empty. */
  bool empty() {
    return st1.empty();
  }
};

int main(void) {
  MyQueue* q = new MyQueue();
  q->push(1);
  int param_2 = q->pop();
  int param_3 = q->peek();
  bool param_4 = q->empty();
  return 0;
}
