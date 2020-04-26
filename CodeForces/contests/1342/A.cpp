#include <iostream>
using int64 = long long int;
using namespace std;

int main(void) {
  int tc, x, y, a, b;
  cin >> tc;
  while (tc--) {
    cin >> x >> y >> a >> b;
    int64 result = 0;
    int greatest = max(x,y);
    int smallest = min(x,y);
    int64 times = greatest - smallest;
    result += (a * times);
    // now they're equals
    int64 c = min(b, 2 * a);
    result += (c * smallest);
    cout << result << endl;
  }
  return 0;
}