#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* ans = Advance(head, head->val);
    if (ans == nullptr) {
      return nullptr;
    }
    ans->next = deleteDuplicates(ans->next);
    return ans;
  }
private:
  ListNode* Advance(ListNode* head, int val) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    if (head->val != head->next->val) {
      return head;
    }
    while (head != nullptr && head->val == val) {
      head = head->next;
    }
    if (head == nullptr) {
      return head;
    }
    return Advance(head, head->val);
  }
};

void Print(ListNode *l) {
  while (l != nullptr) {
    cout << l->val << "->";
    l = l->next;
  }
  cout << "X" << endl;
}

int main(void) {
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(3);
  l1->next->next->next = new ListNode(3);
  l1->next->next->next->next = new ListNode(4);
  l1->next->next->next->next->next = new ListNode(4);
  l1->next->next->next->next->next->next = new ListNode(5);
  Print(l1);

  Solution sol;
  ListNode *ans = sol.deleteDuplicates(l1);
  Print(ans);
  return 0;
}