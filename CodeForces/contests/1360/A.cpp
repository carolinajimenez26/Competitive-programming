#include <iostream>
using namespace std;

int main(void) {
  int tc, a, b;
  cin >> tc;
  while (tc--) {
    cin >> a >> b;
    int width = min(a,b) * 2;
    int heigh = max(a,b);
    int x = max(width,heigh);
    cout << (x * x) << endl;
  }
  return 0;
}