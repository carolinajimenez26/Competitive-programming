#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

stack<int> getValues(ListNode* l) {
  stack<int> result;
  while (l != NULL) {
    result.push(l->val);
    l = l->next;
  }
  return result;
}

int getNextOrOne(stack<int>& st) {
  int x;
  if (st.empty()) {
    x = 0;
  } else {
    x = st.top();
    st.pop();
  }
  return x;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  stack<int> st_l1, st_l2;
  int x, y, carry = 0, z;
  st_l1 = getValues(l1);
  st_l2 = getValues(l2);
  ListNode* head = new ListNode(-1);

  while (!st_l1.empty() || !st_l2.empty()) {
    x = getNextOrOne(st_l1);
    y = getNextOrOne(st_l2);
    z = x + y + carry;

    if (z >= 10) {
      carry = 1;
      z -= 10;
    } else {
      carry = 0;
    }

    if (head->val == -1) {
      head->val = z;
    } else {
      ListNode* node = new ListNode(z);
      node->next = head;
      head = node;
    }
  }

  if (carry) {
    ListNode* node = new ListNode(1);
    node->next = head;
    head = node;
  }
  return head;
}

int main(void) {
  return 0;
}
