package LeetCode.MergeTwoSortedLists;

public class Main {
  public static void main(String[] args) {

    // SimpleLinkedList sll = new SimpleLinkedList(new int[]{1, 2, 4});
    // sll.print();

    Test[] tests = new Test[]{
      new Test(
        new SimpleLinkedList(new int[]{1, 2, 4}),
        new SimpleLinkedList(new int[]{1, 3, 4}),
        new SimpleLinkedList(new int[]{1, 1, 2, 3, 4, 4})
      ),
      new Test(
        new SimpleLinkedList(new int[]{}),
        new SimpleLinkedList(new int[]{1, 3, 4}),
        new SimpleLinkedList(new int[]{1, 3, 4})
      ),
      new Test(
        new SimpleLinkedList(new int[]{1, 2, 4}),
        new SimpleLinkedList(new int[]{}),
        new SimpleLinkedList(new int[]{1, 2, 4})
      ),
      new Test(
        new SimpleLinkedList(new int[]{}),
        new SimpleLinkedList(new int[]{}),
        new SimpleLinkedList(new int[]{})
      ),
      new Test(
        new SimpleLinkedList(new int[]{5,5,6}),
        new SimpleLinkedList(new int[]{1,1,1}),
        new SimpleLinkedList(new int[]{1,1,1,5,5,6})
      ),
    };

    Solution solution = new Solution();
    boolean succeeded = true;
    int testNumber = 0;
    for (Test test : tests) {
      test.print();
      SimpleLinkedList simpleLinkedList1 = new SimpleLinkedList(test.a.getHead());
      SimpleLinkedList simpleLinkedList2 = new SimpleLinkedList(test.b.getHead());
      ListNode resultHead = solution.mergeTwoLists(simpleLinkedList1.getHead(), simpleLinkedList2.getHead());
      SimpleLinkedList result = new SimpleLinkedList(resultHead);
      if (!result.equals(test.expected)) {
        succeeded = false;
        System.out.println("Failed for test #" + testNumber);
        System.out.println("Got");
        result.print();
      } else {
        System.out.println("Succeeded for test #" + testNumber);
      }
      testNumber++;
    }

    if (succeeded) {
      System.out.println("All good");
    } else {
      System.out.println("There's a bug");
    }
  }
}

/**
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * 21. Merge Two Sorted Lists Solved Easy Topics Companies

 *  *You are given the heads of two sorted linked lists list1 and list2.

 *  *Merge the two lists into one sorted list. The list should be made by splicing
 * together the nodes of the first two lists.

 *  *Return the head of the merged linked list.
 *
 *

 *  *Example 1:

 *  *Input: list1 = [1,2,4], list2 = [1,3,4] Output: [1,1,2,3,4,4]

 *  *Example 2:

 *  *Input: list1 = [], list2 = [] Output: []

 *  *Example 3:

 *  *Input: list1 = [], list2 = [0] Output: [0]
 *
 *

 *  *Constraints:

 *  *The number of nodes in both lists is in the range [0, 50]. -100 <= Node.val
 * <= 100 Both list1 and list2 are sorted in non-decreasing order.
 *
 */
