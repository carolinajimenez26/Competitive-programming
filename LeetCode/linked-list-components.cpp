#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

set<int> createSet(vector<int>& G) {
  set<int> result;
  for (auto e : G) {
    result.insert(e);
  }
  return result;
}

int numComponents(ListNode* head, vector<int>& G) {
  int result = 0;
  set<int> head_subset = createSet(G);
  int size = 0;
  while (head != NULL) {
    if (head_subset.count(head->val)) size++;
    else {
      if (size) result++;
      size = 0;
    }
    head = head->next;
  }
  if (size) result++;
  return result;
}

int main(void) {

  return 0;
}
