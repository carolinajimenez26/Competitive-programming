#include <iostream>
using namespace std;
using int64 = long long int;
#define dbg(x) cout << #x << ": " << x << endl

int HowManyTimesTo1(int64 n) {
  int times = 0;
  while (n > 1) {
    int64 reminder = n % 6;
    if (reminder > 0) {
      if ((n * 2) % 6 > 0) return -1;
      n *= 2;
    } else {
      n /= 6;
    }
    times++;
  }
  return times;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int64 n;
    cin >> n;
    cout << HowManyTimesTo1(n) << endl;
  }
  return 0;
}