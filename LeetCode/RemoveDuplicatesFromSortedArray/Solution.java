package LeetCode.removeDuplicatesFromSortedArray;

import java.util.*;

class Solution {
    public int removeDuplicates(int[] nums) {
      if (nums.length == 0) {
        return 0;
      }
      
      int i = findFirstRepeatedOccurrenceIndex(nums, 1);;
      int j = findFirstOccurrenceIndex(nums, i + 1, nums[i]);

      for (; i < nums.length && i < j; i++) {
        swap(nums, i, j);
        j = findFirstOccurrenceIndex(nums, j + 1, nums[i - 1]);
      }

      return i;
    }

    private int findFirstOccurrenceIndex(int[] nums, int i, int val) {
      for (; i < nums.length; i++) {
        if (nums[i] > val) {
          return i;
        }
      }
      return nums.length;
    }

    private int findFirstRepeatedOccurrenceIndex(int[] nums, int i) {
      for (; i < nums.length; i++) {
        if (nums[i] == nums[i - 1]) {
          return i;
        }
      }
      return nums.length;
    }

    private void swap(int[] nums, int i, int j) {
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
    }
}

/*
  https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150

  [1,1,2]
     i j

  [0,0,1,1,1,2,2,3,3,4] --> [0,1,2,1,1,0,2,3,3,4] --> [0,1,2,3,1,0,2,1,3,4] --> [0,1,2,3,4,0,2,1,3,1] --> [0,1,2,3,4,0,2,1,3,1]
     i j                         i     j                     i       j                   i         j                 i         j


  [0,1,1,1,1,2,2,3,3,4]
     i       j


  [0,1,2,1,1,2,2,3,3,4]
     i j

  [0,1,2,3,4,4,4,5,6,7] --> [0,1,2,3,4,5,6,4,4,7] --> [0,1,2,3,4,5,6,7,4,4]
             i   j                       i   j                       i   j

*/