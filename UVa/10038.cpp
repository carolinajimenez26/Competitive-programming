#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
bitset<3000> bs;

int main(void) {
  int n, first, number;
  bool ans;
  while (cin >> n) {
    bs.reset();
    ans = false;
    cin >> first;
    if (n == 1) ans = true;
    else {
      int tmp = 0;
      for (int i = 1; i < n; i++) {
        cin >> number;
        if (i == 1) {
          bs[abs(first - number)] = 1;
        } else {
          bs[abs(tmp - number)] = 1;
        }
        tmp = number;
      }
      if (bs.count() == n - 1 and !bs[n]) ans = true;
    }

    if (ans) cout << "Jolly" << endl;
    else cout << "Not jolly" << endl;
  }
  return 0;
}
