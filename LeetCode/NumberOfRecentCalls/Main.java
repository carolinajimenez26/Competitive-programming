package LeetCode.NumberOfRecentCalls;

public class Main {
  public static void main(String[] args) {
    // [], [1], [100], [3001], [3002]
    Test[] tests = new Test[] {
        new Test(1, 1), // [1 - 3000 = -2999, 1]
        new Test(100, 2), // [100 - 3000 = -2900, 100]
        new Test(3001, 3), // [3001 - 3000 = 1, 3001]
        new Test(3002, 3), // [3002 - 3000 = 2, 3002]
        new Test(3100, 4), // [3100 - 3000 = 100, 3100]
        new Test(3101, 4), // [3101 - 3000 = 101, 3100]
        new Test(6000, 5), // [6000 - 3000 = 3000, 6000]
        new Test(7000, 2), // [7000 - 3000 = 4000, 7000]
        new Test(14000, 1), // [14000 - 3000 = 11000, 14000]
    };

    RecentCounter rc = new RecentCounter();
    boolean succeeded = true;
    for (Test test : tests) {
      if (rc.ping(test.time) != test.expected) {
        System.out.println("Test failed for input " + test.time);
        succeeded = false;
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
 * https://leetcode.com/problems/number-of-recent-calls/description/
 * 
 * 933. Number of Recent Calls
 * Easy
 * Topics
 * Companies
 * 
 * You have a RecentCounter class which counts the number of recent requests
 * within a certain time frame.
 * 
 * Implement the RecentCounter class:
 * 
 * RecentCounter() Initializes the counter with zero recent requests.
 * int ping(int t) Adds a new request at time t, where t represents some time in
 * milliseconds, and returns the number of requests that has happened in the
 * past 3000 milliseconds (including the new request). Specifically, return the
 * number of requests that have happened in the inclusive range [t - 3000, t].
 * 
 * It is guaranteed that every call to ping uses a strictly larger value of t
 * than the previous call.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input
 * ["RecentCounter", "ping", "ping", "ping", "ping"]
 * [[], [1], [100], [3001], [3002]]
 * Output
 * [null, 1, 2, 3, 3]
 * 
 * Explanation
 * RecentCounter recentCounter = new RecentCounter();
 * recentCounter.ping(1); // requests = [1], range is [-2999,1], return 1
 * recentCounter.ping(100); // requests = [1, 100], range is [-2900,100], return
 * 2
 * recentCounter.ping(3001); // requests = [1, 100, 3001], range is [1,3001],
 * return 3
 * recentCounter.ping(3002); // requests = [1, 100, 3001, 3002], range is
 * [2,3002], return 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 1 <= t <= 109
 * Each test case will call ping with strictly increasing values of t.
 * At most 104 calls will be made to ping.
 * 
 */