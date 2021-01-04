#include <iostream>
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) {
      return nullptr;
    }
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    ListNode* ans;
    if (l1->val < l2->val) {
      ans = l1;
      l1 = l1->next;
    } else {
      ans = l2;
      l2 = l2->next;
    }
    
    ans->next = mergeTwoLists(l1,l2);
    return ans;
  }
};

void Print(ListNode *l) {
  while (l != nullptr) {
    cout << l->val << "->";
    l = l->next;
  }
  cout << "X" << endl;
}

/*
Test cases:

[], [] => []
[], [1,2] => [1,2]
[1,2], [] => [1,2]
[2,3], [1] => [1,2,3]
[2,4], [3] => [2,3,4]

*/

int main(void) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);

  ListNode *l2 = new ListNode(3);

  Solution sol;
  ListNode *merged = sol.mergeTwoLists(l1,l2);
  Print(merged);
  return 0;
}