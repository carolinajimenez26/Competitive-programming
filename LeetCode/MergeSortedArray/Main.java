package LeetCode.MergeSortedArray;

import java.util.ArrayList;
import java.util.List;

public class Main {
  public static void main(String[] args) {
    Solution solution = new Solution();
    List<Test> tests = new ArrayList();

    SolutionArguments solutionArguments1 = new SolutionArguments(new int[] { 1, 2, 3, 0, 0, 0 }, 3,
        new int[] { 2, 5, 6 }, 3);
    Test test1 = new Test(solution, solutionArguments1, new int[] { 1, 2, 2, 3, 5, 6 });
    test1.run();
    tests.add(test1);

    SolutionArguments solutionArguments2 = new SolutionArguments(new int[] { 1 },
        1, new int[] {}, 0);
    Test test2 = new Test(solution, solutionArguments2, new int[] { 1 });
    test2.run();
    tests.add(test2);

    SolutionArguments solutionArguments3 = new SolutionArguments(new int[] { 0 }, 0,
        new int[] { 1 }, 1);
    Test test3 = new Test(solution, solutionArguments3, new int[] { 1 });
    test3.run();
    tests.add(test3);

    SolutionArguments solutionArguments4 = new SolutionArguments(new int[] { 0,
        0, 0, 0 }, 2, new int[] { 5, 5 }, 2);
    Test test4 = new Test(solution, solutionArguments4, new int[] { 0, 0, 5, 5
    });
    test4.run();
    tests.add(test4);

    SolutionArguments solutionArguments5 = new SolutionArguments(new int[] { 5,
        5, 0, 0 }, 2, new int[] { 5, 5 }, 2);
    Test test5 = new Test(solution, solutionArguments5, new int[] { 5, 5, 5, 5 });
    test5.run();
    tests.add(test5);

    SolutionArguments solutionArguments6 = new SolutionArguments(new int[] {}, 0, new int[] {}, 0);
    Test test6 = new Test(solution, solutionArguments6, new int[] {});
    test6.run();
    tests.add(test6);

    SolutionArguments solutionArguments7 = new SolutionArguments(new int[] { 4, 0, 0, 0, 0, 0 }, 1, new int[] { 1, 2, 3,
        5, 6 }, 5);
    Test test7 = new Test(solution, solutionArguments7, new int[] { 1, 2, 3, 4, 5, 6 });
    test7.run();
    tests.add(test7);

    boolean succeeded = true;
    for (int i = 0; i < tests.size(); i++) {
      if (tests.get(i).succeeded == false) {
        System.out.println("There's a bug");
        succeeded = false;
        return;
      }
    }
    if (succeeded)
      System.out.println("All good!");
  }
}

/*
 * https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId
 * =top-interview-150
 * 
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing
 * order, and two integers m and n, representing the number of elements in nums1
 * and nums2 respectively.
 * 
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * 
 * The final sorted array should not be returned by the function, but instead be
 * stored inside the array nums1. To accommodate this, nums1 has a length of m +
 * n, where the first m elements denote the elements that should be merged, and
 * the last n elements are set to 0 and should be ignored. nums2 has a length of
 * n.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 * The result of the merge is [1,2,2,3,5,6] with the underlined elements coming
 * from nums1.
 * 
 * Example 2:
 * 
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * Explanation: The arrays we are merging are [1] and [].
 * The result of the merge is [1].
 * 
 * Example 3:
 * 
 * Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 * Output: [1]
 * Explanation: The arrays we are merging are [] and [1].
 * The result of the merge is [1].
 * Note that because m = 0, there are no elements in nums1. The 0 is only there
 * to ensure the merge result can fit in nums1.
 * 
 * 
 * 
 * Constraints:
 * 
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -109 <= nums1[i], nums2[j] <= 109
 * 
 * 
 * Follow up: Can you come up with an algorithm that runs in O(m + n) time?
 * 
 * 
 */