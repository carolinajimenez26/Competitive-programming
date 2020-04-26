#include <iostream>
using namespace std;

int main(void) {
  int tc, n, a, b, c, d;
  cin >> tc;
  while (tc--) {
    cin >> n >> a >> b >> c >> d;
    int min_weigh_rice = (a - b) * n;
    int max_weigh_rice = (a + b) * n;
    int min_weigh_package = c - d;
    int max_weigh_package = c + d;
    if (max(min_weigh_rice, min_weigh_package) <= min(max_weigh_rice, max_weigh_package)) {
      cout << "Yes" << endl;
    } else cout << "No" << endl;
  }
  return 0;
}