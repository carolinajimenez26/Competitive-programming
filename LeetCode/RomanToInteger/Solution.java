package LeetCode.RomanToInteger;

import java.util.HashMap;

class Solution {
  private SimpleDebugger debugger;
  public Solution(SimpleDebugger debugger) {
    this.debugger = debugger;
  }

  private HashMap<Character, Integer> romanToIntMapping = new HashMap<Character, Integer>() {{
    put('I', 1);
    put('V', 5);
    put('X', 10);
    put('L', 50);
    put('C', 100);
    put('D', 500);
    put('M', 1000);
  }};

  public Solution() {}

  public HashMap<Character, Integer> getMapping() {
    return romanToIntMapping;
  }

  // "MCMXCIV"
  public int romanToInt(String s) {
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
      // if I'm smaller than next element, I should be substracted
      if (i + 1 < s.length() && isSmaller(s.charAt(i), s.charAt(i + 1))) {
        result -= romanToIntMapping.get(s.charAt(i));
      } else {
        result += romanToIntMapping.get(s.charAt(i));
      }
    }

    return result;
  }

  public int romanToInt1(String s) {
    int result = 0;

    for (int i = 0; i < s.length();) {
      debugger.print(s + ", position " + i + ", curr char " + s.charAt(i));
      if (i + 1 < s.length() && isSmaller(s.charAt(i), s.charAt(i + 1))) {
        result += romanToIntMapping.get(s.charAt(i + 1)) - romanToIntMapping.get(s.charAt(i));
        i += 2;
      } else {
        result += romanToIntMapping.get(s.charAt(i));
        i++;
      }
    }

    return result;
  }

  private boolean isSmaller(char a, char b) {
    return romanToIntMapping.get(a) < romanToIntMapping.get(b);
  }
}
