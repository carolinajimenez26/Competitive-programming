package LeetCode.MergeTwoSortedLists;

class Solution {
  public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
    return mergeTwoListsRecursive(list1, list2);
  }

  private ListNode mergeTwoListsRecursive(ListNode list1, ListNode list2) {
    if (list1 == null && list2 == null) {
      return null;
    }
    if (list1 == null) {
      return list2;
    }
    if (list2 == null) {
      return list1;
    }
    ListNode newNode = new ListNode(Math.min(list1.val, list2.val));

    if (list1.val < list2.val) {
      newNode.next = mergeTwoListsRecursive(list1.next, list2);
    } else {
      newNode.next = mergeTwoListsRecursive(list1, list2.next);
    }
    return newNode;
  }

  private ListNode mergeTwoListsIterative(ListNode list1, ListNode list2) {
    ListNode result = null;
    ListNode current = null;
    ListNode prev = null;
    while (list1 != null || list2 != null) {
      // System.out.println("Processing...");
      int a = getVal(list1);
      int b = getVal(list2);
      // System.out.println("Adding " + Math.min(a,b));
      if (a < b) {
        current = list1;
        list1 = getNext(list1);
      } else {
        current = list2;
        list2 = getNext(list2);
      }
      
      if (result == null) {
        result = current; 
      }
      if (prev != null) {
        prev.next = current;
      }
      prev = current;
    }
    return result;
  }

  private int getVal(ListNode node) {
    if (node == null) {
      return Integer.MAX_VALUE;
    }
    return node.val;
  }

  private ListNode getNext(ListNode node) {
    if (node == null) {
      return null;
    }
    return node.next;
  }
}
