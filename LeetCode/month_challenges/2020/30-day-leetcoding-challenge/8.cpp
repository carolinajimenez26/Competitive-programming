#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    int slow_i, fast_i;
    slow_i = fast_i = 0;
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
      slow = slow->next;
      slow_i++;
      fast = fast->next->next;
      fast_i += 2;
    }
    int size = (fast->next == NULL ? fast_i + 1 : fast_i + 2);
    int mid = size / 2;
    if (slow_i != mid) {
      slow_i++;
      slow = slow->next;
    }
    return slow;
  }
};

int main(void) {
  return 0;
}