#include <iostream>
using namespace std;
using int64 = long long int;

int64 HowManyMults(int64 a, int64 b) {
  int64 ans = 0;
  int64 times = b / a;
  int curr = 8;
  while (times > 1) {
    if (curr == 1) {
      return -1;
    }
    if (times % curr == 0) {
      ans++;
      times /= curr;
    } else {
      curr >>= 1;
    }
  }
  return ans;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int64 a, b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << endl;
      continue;
    }
    if (b % a != 0 && a % b != 0) {
      cout << -1 << endl;
      continue;
    }
    cout << HowManyMults(min(a,b), max(a,b)) << endl;
  }
  return 0;
}