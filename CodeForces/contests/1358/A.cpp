#include <iostream>
using namespace std;

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int rows, cols, ans = 0;
    cin >> rows >> cols;
    ans += ((cols / 2) * rows);
    if (cols % 2 != 0) {
      ans += (rows / 2);
      if (rows % 2 != 0) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}