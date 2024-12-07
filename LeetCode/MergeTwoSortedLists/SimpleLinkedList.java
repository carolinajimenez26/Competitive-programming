package LeetCode.MergeTwoSortedLists;

public class SimpleLinkedList {
    private ListNode head = null;
    private ListNode tail = null;
    private int size = 0;
    
    public SimpleLinkedList() {}

    public SimpleLinkedList(ListNode head) {
      if (head == null) {
        return;
      }
      this.head = head;
      tail = head;
      size++;
      ListNode current = head;
      while (current.next != null) {
        current = current.next;
        tail = current;
        size++;
      }
    }

    public SimpleLinkedList(int[] list) {
      if (list.length == 0) {
        return;
      }

      ListNode current = new ListNode(list[0]);
      head = current;
      size++;

      for (int i = 1; i < list.length; i++) {
        ListNode newNode = new ListNode(list[i]);
        ListNode prev = current;
        prev.next = newNode;
        size++;
        current = newNode;
      }

      tail = current;
    }

    public ListNode getHead() {
      return head;
    }

    public ListNode getTail() {
      return tail;
    }

    public int getSize() {
      return size;
    }

    public void add(ListNode newNode) {
      tail.next = newNode;
      tail = newNode;
      size++;
    }

    public boolean equals(SimpleLinkedList other) {
      if (size != other.getSize()) {
        return false;
      }
      if (size == 0 && other.getSize() == 0) {
        return true;
      }

      ListNode a = head;
      ListNode b = other.head;
      while (a != null && b != null) {
        if (a.val != b.val) {
          return false;
        }
        a = a.next;
        b = b.next;
      }
      return true;
    }

    public void print() {
      if (size == 0) {
        System.out.println("{}");
        return;
      }
      ListNode node = head;
      System.out.print("{");
      while (node != null) {
        System.out.print(node.val + " -> ");
        node = node.next;
      }
      System.out.println("}. head " + head.val + " tail " + tail.val + " size " + size);
    }
}
