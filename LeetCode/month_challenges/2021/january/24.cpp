#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

const int INF = numeric_limits<int>::max();
struct ListIterator {
  ListNode* l;

  ListIterator(ListNode* l): l(l) {}

  void Advance() {
    if (l == nullptr) {
      return;
    }
    l = l->next;
  }

  int GetValue() const {
    if (l == nullptr) {
      return INF;
    }
    return l->val;
  }

  void Print() {
    if (l == nullptr) {
      cout << "X";
    } else {
      cout << GetValue();
    }
    cout << endl;
  }

  bool operator<(const ListIterator& other) const {
    return GetValue() < other.GetValue();
  }
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    multiset<ListIterator> lists_set;
    for (auto l : lists) {
      lists_set.emplace(l);
    }
    if (lists_set.empty()) {
      return nullptr;
    }
    ListNode* head = GetMin(lists_set);
    ListNode* curr = head;
    while (curr != nullptr) {
      curr->next = GetMin(lists_set);
      curr = curr->next;
    }
    return head;
  }
private:
  void Print(const multiset<ListIterator>& lists_set) {
    cout << "====" << endl;
    for (auto li : lists_set) {
      li.Print();
    }
    cout << "====" << endl;
  }

  ListNode* GetMin(multiset<ListIterator>& lists_set) {
    // Print(lists_set);
    ListIterator smaller = *lists_set.begin();
    if (smaller.GetValue() == INF) {
      return nullptr;
    }
    ListNode* min_head = new ListNode(smaller.GetValue());
    lists_set.erase(lists_set.begin());
    smaller.Advance();
    lists_set.insert(smaller);
    return min_head;
  }
};

ListNode* Convert(const vector<int>& v) {
  if (v.empty()) {
    return nullptr;
  }
  ListNode* head = new ListNode(v[0]);
  ListNode* curr = head;
  for (int i = 1; i < v.size(); i++) {
    curr->next = new ListNode(v[i]);
    curr = curr->next;
  }
  return head;
}

vector<ListNode*> Convert(const vector<vector<int>>& elems) {
  vector<ListNode*> ans;
  for (auto e : elems) {
    ans.push_back(Convert(e));
  }
  return ans;
}

vector<int> Convert(ListNode* l) {
  vector<int> ans;
  while (l != nullptr) {
    ans.push_back(l->val);
    l = l->next;
  }
  return ans;
}

struct Test {
  vector<vector<int>> lists;
  vector<int> expected;
};

int main(void) {
  vector<Test> tests = {
    { {{1,4,5},{1,3,4},{2,6}}, {1,1,2,3,4,4,5,6} },
    { {}, {} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<ListNode*> in = Convert(test.lists);
    ListNode* out = sol.mergeKLists(in);
    vector<int> out_numbers = Convert(out);
    if (out_numbers != test.expected) {
      cout << "Failed on test #" << tc << endl;
      Print(out_numbers);
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}