#include <iostream>
#define dbg(x) cout << #x << ": " << x << endl
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
  ListNode* FindOneBefore(ListNode* root, int target) {
    ListNode* curr = root;
    ListNode* next = curr->next;
    while (curr != nullptr) {
      if (next == nullptr) break;
      if (next->val == target) {
        return curr;
      }
      curr = next;
      next = curr->next;
    }
    return nullptr;
  }

  ListNode* Find(ListNode* root, int target) {
    ListNode* curr = root;
    ListNode* ans = nullptr;
    while (curr != nullptr) {
      if (curr->val == target) {
        return curr->next;;
      }
      curr = curr->next;
    }
    return nullptr;
  }

  ListNode* GetTail(ListNode* root) {
    ListNode* ans = root;
    while (ans != nullptr && ans->next != nullptr) {
      ans = ans->next;
    }
    return ans;
  }

  void Remove(ListNode* from, ListNode* to) {
    if (from == nullptr || to == nullptr) return; // error
    ListNode* curr = from;
    while (from != to) {
      ListNode* tmp = from->next;
      delete from;
      from = tmp;
    }
  }

public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    if (list1 == nullptr && list2 == nullptr) return nullptr;
    if (list1 == nullptr) return list2;

    ListNode* before_a = FindOneBefore(list1, a);
    ListNode* node_b = Find(list1, b);
    Remove(Find(list1, a), node_b);

    before_a->next = list2;

    if (list2 == nullptr) {
      before_a->next = node_b;
      return list1;
    }

    ListNode* list2_tail = GetTail(list2); // from here, list2 has to have at least 1 node
    list2_tail->next = node_b;

    return list1;
  }
};

int main(void) {
  ListNode* head1 = new ListNode(0);
  head1->next = new ListNode(1);
  head1->next->next = new ListNode(2);
  head1->next->next->next = new ListNode(3);
  head1->next->next->next->next = new ListNode(4);
  head1->next->next->next->next->next = new ListNode(5);

  ListNode* head2 = new ListNode(1000000);
  head2->next = new ListNode(10000001);
  head2->next->next = new ListNode(10000002);

  Solution sol;
  sol.mergeInBetween(head1, 3, 4, head2);
  /*
    [0,1,2,3,4,5]
    3
    4
    [1000000,1000001,1000002]

    expected: [0,1,2,1000000,1000001,1000002,5]
  */
  return 0;
}