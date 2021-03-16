#include <iostream>
using namespace std;

class Node {
public:
  Node(int val) : val(val) {}

  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
private:
  Node* Create(Node* curr, Node* next) {
    curr->next = next;
    next->prev = curr;
    curr = next;
    return next;
  }

  void Visit(Node* curr, Node*& ans) {
    if (curr == nullptr) {
      return;
    }
    ans = Create(ans, new Node(curr->val));
    Visit(curr->child, ans);
    Visit(curr->next, ans);
  }

public:
  Node* flatten(Node* head) {
    if (head == nullptr) {
      return nullptr;
    }
    Node* ans_head = new Node(head->val);
    Node* curr = ans_head;
    Visit(head->child, curr);
    Visit(head->next, curr);
    return ans_head;
  }
};

void Print(Node* head) {
  while (head != nullptr) {
    cout << head->val << "->";
    head = head->next;
  }
  cout << "X" << endl;
}

int main(void) {
  Node* head = new Node(1);
  head->next = new Node(2);
  head->child = new Node(3);
  head->child->next = new Node(4);
  head->child->next->child = new Node(5);
  head->child->next->next = new Node(6);
  // 1->3->4->5->6->2
  Solution sol;
  Node* flattened = sol.flatten(head);
  Print(flattened); 
  return 0;
}