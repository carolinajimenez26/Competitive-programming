/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Problem source: https://leetcode.com/problems/add-two-numbers/
*/
#include <iostream>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* convert(string n, int index) {
  if (index < 0) return NULL;
  ListNode* l2 = new ListNode(n[index] - '0');
  l2->next = convert(n, index - 1);
  return l2;
}

void print(ListNode* l) {
  if (l == NULL) {
    cout << endl;
    return;
  }
  cout << l->val << "->";
  print(l->next);
}

void add(ListNode* l1, ListNode* l2) {
  int n;
  while (l2 != NULL) {
    n = l1->val + l2->val;
    l1->val = (n % 10);

    if (n >= 10) {
      ListNode* l = new ListNode(1);
      // l->val = 1;
      l1->next = l;
    } else {
      if (l2->next != NULL) {
        ListNode* l = new ListNode(0);
        // l->val = 0;
        l1->next = l;
      }
    }

    l1 = l1->next;
    l2 = l2->next;
  }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int n = l1->val + l2->val;
  ListNode* result = new ListNode(n % 10);
  result->val = n % 10;

  ListNode* pointerToResult = new ListNode(0);
  pointerToResult->next = result;

  if (n >= 10) {
    ListNode* l = new ListNode(1);
    // l->val = 1;
    result->next = l;
  } else {
    if (l1->next != NULL || l2->next != NULL) {
      ListNode* l = new ListNode(0);
      // l->val = 0;
      result->next = l;
    }
  }
  result = result->next;
  l1 = l1->next;
  l2 = l2->next;

  while (l1 != NULL && l2 != NULL) {
    n = l1->val + l2->val + result->val;
    result->val = n % 10;

    if (n >= 10) {
      ListNode* l = new ListNode(1);
      result->next = l;
    } else {
      ListNode* l = new ListNode(0);
      if (l1->next != NULL || l2->next != NULL)  result->next = l;
    }
    if (l1->next != NULL || l2->next != NULL)  result = result->next;

    l1 = l1->next;
    l2 = l2->next;
  }

  // Add the rest
  if (l1 != NULL) {
    add(result, l1);
  } else {
    if (l2 != NULL) add(result, l2);
  }

  return pointerToResult->next;
}

int main(void) {
  // ListNode* l1 = convert("73", 1);
  // ListNode* l2 = convert("29", 1);
  // output: 2->0->1

  // ListNode* l1 = convert("342", 2);
  // ListNode* l2 = convert("465", 2);
  // output: 7->0->8

  // ListNode* l1 = convert("3342", 3);
  // ListNode* l2 = convert("465", 2);
  // output: 7->0->8->3

  // ListNode* l1 = convert("9", 0);
  // ListNode* l2 = convert("9999999991", 9);
  // output: 0->0->0->0->0->0->0->0->0->0->1

  string s1 = "1000000000000000000000000000001";
  ListNode* l1 = convert(s1, s1.size() - 1);
  ListNode* l2 = convert("465", 2);
  // output: [6,6,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]

  print(l1); print(l2);
  ListNode* l3 = addTwoNumbers(l1, l2);
  print(l3);
  return 0;
}
