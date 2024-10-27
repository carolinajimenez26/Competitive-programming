package LeetCode.MergeSortedArray;

import java.util.Arrays;

class Solution {
  public void merge(int[] nums1, int m, int[] nums2, int n) {
    int[] result = nums1;
    nums1 = Arrays.copyOf(result, m);

    int nums1Idx = 0, nums2Idx = 0, resultIdx = 0;

    // Time: O(m + n)
    // Space: O(m + n)
    while (resultIdx < result.length && nums1Idx < nums1.length && nums2Idx < nums2.length) {
      // System.out.println(nums1[nums1Idx] + " < " + nums2[nums2Idx] + "?");
      if (nums1[nums1Idx] < nums2[nums2Idx]) {
        result[resultIdx] = nums1[nums1Idx];
        nums1Idx++;
      } else {
        result[resultIdx] = nums2[nums2Idx];
        nums2Idx++;
      }
      // System.out.println("added " + result[resultIdx]);
      resultIdx++;
    }
    // System.out.println("resultIdx " + resultIdx);
    if (nums1Idx < m) {
      resultIdx = copyElements(nums1, nums1Idx, result, resultIdx);
    }
    // System.out.println("resultIdx " + resultIdx);
    if (nums2Idx < n) {
      resultIdx = copyElements(nums2, nums2Idx, result, resultIdx);
    }
    // System.out.println("resultIdx " + resultIdx);
    copyElements(result, nums1);
  }

  private int copyElements(int[] from, int fromIdx, int[] to, int toIdx) {
    if (fromIdx < 0) {
      return toIdx; // error!
    }

    while (toIdx < to.length && fromIdx < from.length) {
      to[toIdx] = from[fromIdx];
      // System.out.println("added " + to[toIdx]);
      toIdx++;
      fromIdx++;
    }

    return toIdx;
  }

  private void copyElements(int[] from, int[] to) {
    if (from.length != to.length) {
      return; // error!
    }

    for (int i = 0; i < from.length; i++) {
      to[i] = from[i];
    }
  }
}