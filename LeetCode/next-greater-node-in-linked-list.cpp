#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> nextLargerNodes(ListNode* head) {
  vector<int> result(10001);
  stack<pair<ListNode*, int> > st;
  st.push(make_pair(head, 0));
  head = head->next;
  int index = 1;
  while (head != NULL) {
    while (!st.empty() && head->val > st.top().first->val) {
      result[st.top().second] = head->val;
      st.pop();
    }
    st.push(make_pair(head, index));
    head = head->next;
    index++;
  }

  while (!st.empty()) {
    result[st.top().second] = 0;
    st.pop();
  }

  result.resize(index);
  return result;
}

int main(void) {
  return 0;
}
