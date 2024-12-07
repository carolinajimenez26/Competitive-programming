package LeetCode.RomanToInteger;

public class SimpleDebugger {
  private boolean isActive = false;

  public SimpleDebugger() {
    isActive = true;
  }

  public void setIsActive(boolean isActive) {
    this.isActive = isActive;
  }

  public void print(String message) {
    if (!isActive) {
      return;
    }
    System.out.println(message);
  }
}