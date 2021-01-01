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
private:
  unordered_set<ListNode*> ordered;

  ListNode* Place(ListNode* head, ListNode* node) {
    if (head == nullptr) {
      return node;
    }
    if (ordered.count(head) == 0) {
      node->next = head;
      return node;
    }
    if (head->val >= node->val) {
      node->next = head;
      return node;
    } 
    head->next = Place(head->next, node);
    return head;
  } 

  ListNode* Remove(ListNode* head, ListNode* node) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head == node) {
      return head->next;
    }
    head->next = Remove(head->next, node);
    return head;
  }
public:
  ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* curr = head;
    while (curr != nullptr) {
      ListNode* next = curr->next;
      head = Remove(head, curr);
      head = Place(head, curr);
      ordered.insert(curr);
      curr = next;
    }
    return head;
  }
};

int main(void) {
  /*
    test cases:
    [4,3,2,1]  -> [1,2,3,4]
    [3] -> [3]
    [] -> []
    [1,2,3] -> [1,2,3]
    [2,1] -> [1,2]
    [1,2] -> [1,2]
    [1,3,1,3,2,2] -> [1,1,2,2,3,3]
  */
  return 0;
}