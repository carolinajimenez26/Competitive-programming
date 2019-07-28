#include <iostream>

using namespace std;

bool timesTo(int n, int target, int& times) {
  if (n == target) return true;
  if (n > target) {
    // times--;
    return false;
  }
  // times++;
  if (timesTo(n * 2, target, times)) {
    times++;
    return true;
  }
  bool result = timesTo(n * 3, target, times);
  if (result) times++;
  return result;
}

int main(void) {
  int n, m, result = 0;
  cin >> n >> m;
  bool found = timesTo(n, m, result);
  cout << (found ? result : -1) << endl;
  return 0;
}
