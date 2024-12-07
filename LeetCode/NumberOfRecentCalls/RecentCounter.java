package LeetCode.NumberOfRecentCalls;

import java.util.LinkedList;
import java.util.Queue;

class RecentCounter {
  private final Queue<Integer> queue = new LinkedList<>();
  private final int elapsedTime = 3000;

  public RecentCounter() {
  }

  // Time: O(n)
  // Space: O(n)
  public int ping(int t) {
    int fromRage = t - elapsedTime;
    // System.out.println("from " + fromRage);
    queue.add(t);
    int top = queue.peek();
    while (top < fromRage) {
      // System.out.println("top " + top);
      queue.poll();
      top = queue.peek();
    }
    // System.out.println("queue size " + queue.size());
    return queue.size();
  }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */