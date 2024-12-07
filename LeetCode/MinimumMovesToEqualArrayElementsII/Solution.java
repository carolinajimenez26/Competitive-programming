package LeetCode.MinimumMovesToEqualArrayElementsII;

import java.util.HashMap;

/*
[0]

[1]

[]

[1,2,3,4] 
x = nums[4/2] = nums[2] = 3
[2,3,3,3] result = 3 --> [3,3,3,3] result = 4

[1,2,3,4,5]
x = nums[5/2] = nums[2] = 3
[2,3,3,3,4] result = 4 --> [3,3,3,3] result = 6

[1,1,1,1]
x = nums[4/2] = nums[2] = 1
result = 0

[1,2]
x = nums[2/2] = nums[1] = 2
[2,2] result = 1

[1,1,1,5,5,5,5]
A) x = nums[7/2] = nums[3] = 5
[2,2,2,5,5,5,5] result = 3 --> [3,3,3,5,5,5,5] result = 6 --> ... result = 3 * (5-1) = 12
B) x = 1
[1,1,1,4,4,4,4] result = 4 --> ... result = 4 * (5-1) = 16

[1,1,1,2,2,2,2,5,5,5,5,5]
A) x = 1
result = 4 * (2 - 1) + 5 * (5 - 1) = 4 + 20 = 24
B) x = 2
result = 3 * (2 - 1) + 5 * (5 - 2) = 3 + 15 = 18
C) x = 5
result = 3 * (5 - 1) + 4 * (5 - 2) = 12 + 12 = 24

*/

class Solution {
  private HashMap<Integer, Integer> freq = new HashMap<>();

  public int minMoves2(int[] nums) {
    if (nums.length <= 1) return 0;
    Arrays.sort(nums);
    int x = nums[nums.length / 2];
    // System.out.println("x " + x);
    int result = 0;

    fillNumberFrequency(nums);
    // printFreq();

    for (Integer num : freq.keySet()) {
      if (num == x) continue;
      int y = (x - num);
      if (y < 0) y *= -1;
      result += freq.get(num) * y;
    }

    return result;
  }

  private void fillNumberFrequency(int[] nums) {
    for (int num : nums) {
      Integer freqOfNum = freq.get(num);
      if (freqOfNum == null) {
        freq.put(num,1);
      } else {
        freq.put(num,freqOfNum + 1);
      }
    }
  }

  private void printFreq() {
    for (Integer num : freq.keySet()) {
      System.out.println(num + " --> " + freq.get(num));
    }
  }
}

/*

https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

462. Minimum Moves to Equal Array Elements II
Medium
Topics
Companies

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

Example 2:

Input: nums = [1,10,2,9]
Output: 16

 

Constraints:

    n == nums.length
    1 <= nums.length <= 105
    -109 <= nums[i] <= 109



*/