package LeetCode.ValidParentheses;

import java.util.Stack;

class Solution {
  // Time: O(n)
  // Space: O(n)
  public boolean isValid(String s) {
    Stack<Character> stack = new Stack<>();

    for (Character c : s.toCharArray()) {
      // System.out.println(c);
      if (isOpen(c)) {
        // System.out.println("push!");
        stack.push(c);
      } else {
        if (stack.isEmpty()) {
          // System.out.println("empty!");
          return false;
        }
        char top = stack.pop();
        // System.out.println("top " + top);
        if (!matches(top, c)) {
          // System.out.println("not a match!");
          return false;
        }
      }
    }

    // System.out.println("empty? " + stack.empty());
    return stack.isEmpty();
  }

  private boolean isOpen(Character c) {
    return c == '(' || c == '[' || c == '{';
  }

  private boolean matches(char opening, char closed) {
    if (opening == '(' && closed == ')') {
      return true;
    }
    if (opening == '[' && closed == ']') {
      return true;
    }
    if (opening == '{' && closed == '}') {
      return true;
    }

    return false;
  }
}