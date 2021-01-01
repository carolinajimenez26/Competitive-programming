#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  // Runtime: O(size)
  // Space: O(1)
  ListNode* Reverse(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* left = head;
    ListNode* mid = head->next;
    ListNode* right = mid == nullptr ? nullptr : mid->next;
    head->next = nullptr;
    while (mid != nullptr) {
      mid->next = left;
      left = mid;
      mid = right;
      right = right == nullptr? nullptr : right->next;
    }
    return left;
  }
public:
  // Runtime: O(max(l1_size, l2_size))
  // Space: O(max(l1_size, l2_size))
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l1_reversed = Reverse(l1);
    // Print(l1_reversed);
    ListNode* l2_reversed = Reverse(l2);
    // Print(l2_reversed);
    ListNode* curr = new ListNode(0);
    ListNode* head = curr;
    bool carry = false;
    while (l1_reversed != nullptr || l2_reversed != nullptr) {
      int a = l1_reversed == nullptr ? 0 : l1_reversed->val;
      int b = l2_reversed == nullptr ? 0 : l2_reversed->val;
      int sum = a + b + carry;
      carry = false;
      if (sum > 9) {
        carry = true;
      }
      curr->val = sum % 10;
      curr->next = new ListNode(0);
      curr = curr->next;
      l1_reversed = l1_reversed == nullptr ? nullptr : l1_reversed->next;
      l2_reversed = l2_reversed == nullptr ? nullptr : l2_reversed->next;
    }
    if (carry) {
      curr->val = 1;
    }
    // Print(head);
    head = Reverse(head);
    if (head->val == 0) return head->next;
    return head;
  }

  void Print(ListNode* head) {
    while (head != nullptr) {
      cout << head->val;
      head = head->next;
    }
    cout << endl;
  }
};

int main(void) {
  /*
    Test cases:

    9 + 1 = 10
    10 + 4 = 14
    0 + 0 = 0
    99 + 1 = 100
    99 + 9 = 108
  */
  ListNode* l1 = new ListNode(7);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);
  l1->next->next->next = new ListNode(3);  

  ListNode* l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  Solution sol;
  ListNode* ans = sol.addTwoNumbers(l1, l2);
  sol.Print(ans);

  return 0;
}