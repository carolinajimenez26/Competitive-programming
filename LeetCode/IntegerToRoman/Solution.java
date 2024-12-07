package LeetCode.IntegerToRoman;

import java.util.TreeMap;
import java.util.List;
import java.util.ArrayList;

class Solution {
  private TreeMap<Integer, String> romanToIntMapping = new TreeMap<>() {{
    put(1, "I");
    put(4, "IV");
    put(5, "V");
    put(9, "IX");
    put(10, "X");
    put(40, "XL");
    put(50, "L");
    put(90, "XC");
    put(100, "C");
    put(400, "CD");
    put(500, "D");
    put(900, "CM");
    put(1000, "M");
  }};

  private List<Integer> romanToIntMappingKeys = new ArrayList<>(romanToIntMapping.keySet());

  public String intToRoman(int num) {
    if (num <= 0) {
      return ""; // error
    }
    System.out.println(romanToIntMappingKeys);
    return intToRoman(num, 1000).toString();
  }

  // f(1994, 1000)
  //   x = 1994 / 1000 = 1
  //   m = 1994 % 1000 = 994
  //   r = convert(1 * 1000 = 1000)
  //   "M" + f(994, 100)
  private StringBuilder intToRoman(int num, int div) {
    // System.out.println("intToRoman num " + num + " div " + div);
    if (div == 1) {
      return convert(num);
    }
    int x = num / div;
    int mod = num % div;
    StringBuilder result = new StringBuilder();
    result = convert(x * div);
    return result.append(intToRoman(mod, div / 10));
  }

  // num 1
  // key = 1
  // 1 - 1 = 0
  private StringBuilder convert(int num) {
    // System.out.println("convert num " + num);
    StringBuilder result = new StringBuilder();
    if (num == 0) {
      return result;
    }
    // 70 --> LXX
    // 70 --> 70 - 100 = -30
    //        70 - 90 = -20
    //        70 - 50 = 20
    // 20 --> XX
    //        20 - 100 = -80
    //        ...
    //        20 - 10 = 10
    for (int i = romanToIntMappingKeys.size() - 1; i >= 0 ; i--) {
      int key = romanToIntMappingKeys.get(i);
      // System.out.println("key " + key);
      if (num - key >= 0) {
        String roman = romanToIntMapping.get(key);
        result.append(roman);
        num -= key;
        // System.out.println("appending " + roman);
        break;
      }
    }

    return result.append(convert(num));
  }
}

/*
  1234
  1234 % 10 = 4
  1230 % 100 = 30
  1200 % 1000 = 200
  1000 % 10000 = 1000
  1234 = 1000 + 200 + 30 + 4

  1234 / 1000 = 1.234 --> 1000 + rest = 1000 + 1234 % 1000 ==> M + something
  2234 / 1000 = 2.234 ==> MM + something
  234 / 100 ==> 2.34 ==> CC + something
  34 / 10 ==> 3.4 ==> XXX + something
  4 / 1 ==> 4 ==> IIII

  1444 ==> M + CCCC + XXXX + IIII

  1444 ==> M + CCCC + XXXX + IIII

  10 --> 10 * 1 ==> X

  20 --> 10 * 2 ==> XX

  30 --> 10 * 3 ==> XXX

  70 --> LXX
*/