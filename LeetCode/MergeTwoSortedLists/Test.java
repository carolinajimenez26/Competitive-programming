package LeetCode.MergeTwoSortedLists;

public class Test {
  SimpleLinkedList a, b, expected;

  public Test(SimpleLinkedList a, SimpleLinkedList b, SimpleLinkedList expected) {
    this.a = a;
    this.b = b;
    this.expected = expected;
  }

  public void print() {
    System.out.println("=== Test ===");
    a.print();
    b.print();
    System.out.println("Expected");
    expected.print();
  }
}