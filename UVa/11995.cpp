#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct compare {
  bool operator() (const int& l, const int& r) {
      return l < r;
  }
};

void print(priority_queue<int, vector<int>, compare > q) {
  while (!q.empty()) {
    cout << q.top() << endl;
    q.pop();
  }
}

void print(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }
}

void print(stack<int> s) {
  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
}

int main(void) {
  int n, command, x, stack_tmp, queue_tmp, p_queue_tmp;
  int stack_aux, queue_aux, p_queue_aux, command_aux;
  while (cin >> n) {
    stack_aux = queue_aux = p_queue_aux = command_aux = 0;
    stack<int> st;
    queue<int> q;
    priority_queue<int, vector<int>, compare > pq;
    for (int i = 0; i < n; i++) {
      cin >> command >> x;
      if (command == 1) { // push
        st.push(x);
        q.push(x);
        pq.push(x);
      } else { // pop
        command_aux++;
        if (st.size() == 0) stack_aux--;
        else {
          if (st.top() == x) stack_aux++;
          st.pop();
        }
        if (q.size() == 0) queue_aux--;
        else {
          if (q.front() == x) queue_aux++;
          q.pop();
        }
        if (pq.size() == 0) p_queue_aux--;
        else {
          if (pq.top() == x) p_queue_aux++;
          pq.pop();
        }
      }
      // print(st);
      // print(q);
      // print(pq);
    }

    if (command_aux != stack_aux and command_aux != p_queue_aux
        and command_aux != queue_aux) cout << "impossible" << endl;
    if (command_aux == stack_aux and command_aux == p_queue_aux or
        command_aux == stack_aux and command_aux == queue_aux or
        command_aux == queue_aux and command_aux == p_queue_aux)
      cout << "not sure" << endl;
    else {
      if (command_aux == stack_aux) cout << "stack" << endl;
      if (command_aux == p_queue_aux) cout << "priority queue" << endl;
      else {
        if (command_aux == queue_aux) cout << "queue" << endl;
      }
    }
  }

  return 0;
}
