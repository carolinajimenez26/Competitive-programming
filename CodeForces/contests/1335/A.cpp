#include <iostream>

using namespace std;

int main(void) {
  int tc;
  long long int n;
  cin >> tc;
  while (tc--) {
    cin >> n;
    if (n <= 2) {
      cout << 0 << endl;
    } else {
      long long int result = (n / 2);
      long long int res = (n % 2);
      if (res == 0) {
        result--;
      }
      cout << result << endl;
    }
  }
  return 0;
}