package LeetCode.ValidParentheses;

public class Main {
  public static void main(String[] args) {
    Solution solution = new Solution();
    Test[] tests = new Test[] {
        new Test("", true),
        new Test("(", false),
        new Test("(([[))}}", false),
        new Test("()", true),
        new Test("()[]{}", true),
        new Test("(]", false),
        new Test("([])", true),
        new Test("([{{{", false),
        new Test("}}]]", false)
    };

    boolean succeeded = true;
    for (Test test : tests) {
      if (solution.isValid(test.input) != test.expected) {
        succeeded = false;
        System.out.println("Failed for " + test.input);
      }
    }
    if (succeeded) {
      System.out.println("All good");
    } else {
      System.out.println("There is a bug");
    }
  }
}

/*
 * 
 * https://leetcode.com/problems/valid-parentheses/description/?envType=study-
 * plan-v2&envId=top-interview-150
 * 
 * 20. Valid Parentheses
 * Solved
 * Easy
 * Topics
 * Companies
 * Hint
 * 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: s = "()"
 * 
 * Output: true
 * 
 * Example 2:
 * 
 * Input: s = "()[]{}"
 * 
 * Output: true
 * 
 * Example 3:
 * 
 * Input: s = "(]"
 * 
 * Output: false
 * 
 * Example 4:
 * 
 * Input: s = "([])"
 * 
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 104
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */