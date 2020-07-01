#include <iostream>
using namespace std;
using int64 = long long int;
#define dbg(x) cout << #x << ": " << x << endl

int64 BinarySearch(int64 x, int64 y, int64 n) {
  int64 left = 0, right = n;
  while (left < right) {
    // dbg(left); dbg(right);
    int64 mid = (left + right + 1) / 2;
    // dbg(mid);
    int64 curr = x * mid + y;
    // dbg(curr);
    if (curr <= n) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  return x * left + y;;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int64 x,y,n;
    cin >> x >> y >> n;
    cout << BinarySearch(x,y,n) << endl;
  }
  return 0;
}