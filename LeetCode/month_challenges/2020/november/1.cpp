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
private: 
  int GetSize(ListNode* node) {
    if (node == nullptr) return 0;
    return 1 + GetSize(node->next);
  }
  int GetDecimalValue(ListNode* node, int val) {
    if (node == nullptr) return 0;
    return (node->val * val) + GetDecimalValue(node->next, val >> 1);
  }
public:
  int getDecimalValue(ListNode* head) {
    int tree_size = GetSize(head);
    int val = 1 << tree_size - 1;
    return GetDecimalValue(head, val);
  }
};

int main(void) {
  /*
    test cases:

    [1,0,1] --> 5
    [] --> 0
    [0] --> 0
    [0,0,0] -> 0
    [0,0,1] -> 1
    [1,1] -> 3
    [1,1,0] -> 6
  */
  return 0;
}