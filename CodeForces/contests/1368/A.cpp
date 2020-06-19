#include <iostream>
#include <cmath>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b, n;
    cin >> a >> b >> n;
    int smaller = min(a,b);
    int greater = max(a,b);
    int ans = 0;
    // dbg(smaller); dbg(greater); dbg(n);
    if (smaller > n || greater > n) {
      cout << ans << endl;
      continue;
    }
    bool turn = 0;
    while (!(smaller > n || greater > n)) {
      if (turn) {
        greater += smaller;
      } else {
        smaller += greater;
      }
      ans++;
      turn = !turn;
    }
    cout << ans << endl;
  }
  return 0;
}