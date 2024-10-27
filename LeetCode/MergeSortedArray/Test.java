package LeetCode.MergeSortedArray;

public class Test {
  Solution solution;
  SolutionArguments solutionArguments;
  int[] expected;
  boolean succeeded = true;

  Test(Solution solution, SolutionArguments solutionArguments, int[] expected) {
    this.solution = solution;
    this.solutionArguments = solutionArguments;
    this.expected = expected;
  }

  public void run() {
    solution.merge(solutionArguments.nums1, solutionArguments.m, solutionArguments.nums2, solutionArguments.n);
    succeeded = solutionArguments.nums1.length == solutionArguments.m + solutionArguments.n;

    System.out.println("==== Testing ====");
    for (int i = 0; i < solutionArguments.nums1.length; i++) {
      System.out.print(solutionArguments.nums1[i] + " ");

      if (succeeded && solutionArguments.nums1[i] != expected[i]) {
        succeeded = false;
      }
    }

    if (succeeded)
      System.out.println("Test succeeded!");
    else
      System.out.println("Test failed!");
  }
}