#include <iostream>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void Print(ListNode* l) {
  while (l != nullptr) {
    cout << l->val << "->";
    l = l->next;
  }
  cout << "X" << endl;
}

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return AddTwoNumbers(l1,l2,0);
  }
private:
  ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2, bool carry) {
    if (l1 == nullptr && l2 == nullptr) {
      if (carry) {
        return new ListNode(carry);
      }
      return nullptr;
    }
    int val = GetVal(l1) + GetVal(l2) + carry;
    carry = val >= 10;
    ListNode* ans = new ListNode(val % 10);
    ans->next = AddTwoNumbers(Advance(l1), Advance(l2), carry);
    return ans;
  }

  ListNode* Advance(ListNode* l) {
    if (l == nullptr) {
      return nullptr;
    }
    return l->next;
  }

  int GetVal(ListNode* l) {
    if (l == nullptr) {
      return 0;
    }
    return l->val;
  }
};

/*

99
11
-----
011


99
99
-----
891

99
1
-----
001

*/

int main(void) {
  ListNode* l1 = new ListNode(9);
  l1->next = new ListNode(9);

  ListNode* l2 = new ListNode(1);

  Solution sol;
  ListNode* l3 = sol.addTwoNumbers(l1,l2);
  Print(l3);
  return 0;
}