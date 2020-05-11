#include <iostream>
using namespace std;
using int64 = long long int;

// from 1
inline int HowManyNonDivisibleBy(int n, int to) {
  return to - (to / n);
}

int KthNotDivisibleByN(int n, int k) {
  int64 left = 1, right = 2e9 + 5;
  while (left < right) {
    int64 mid = (left + right) / 2;
    if (HowManyNonDivisibleBy(n, mid) < k) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    cout << KthNotDivisibleByN(n, k) << endl;
  }
  return 0;
}