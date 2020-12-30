#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintRecursive(ListNode* head) {
  if (head == nullptr) return;
  cout << head->val << "->";
  PrintRecursive(head->next);
}

void Print(ListNode* head) {
  cout << "----" << endl;
  PrintRecursive(head);
  cout << endl << "----" << endl;
}

class Solution {
public:
  ListNode* swapPairs(ListNode *head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;
    ListNode* a = head;
    ListNode* b = a->next;
    ListNode* c = b->next;
    b->next = a;
    a->next = swapPairs(c);
    return b;
  }
};

int main(void) {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  Print(head);
  Solution sol;
  ListNode* other = sol.swapPairs(head);
  Print(other);
  return 0;
}