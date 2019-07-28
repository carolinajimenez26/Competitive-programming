#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// #define dbg(x) cout << #x << ": " << x << endl
// #define INF numeric_limits<int>::max()

int main(void) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int n, c;
  int numbers[] = {20, 10, 5, 2, 1};
  cin >> n;
  while (n--) {
    int coins = 0;
    cin >> c;
    int i = 0;
    while (c != 0) {
      if (c - numbers[i] >= 0) {
        c -= numbers[i];
        coins++;
      } else {
        i++;
      }
      if (i == 5) i = 0;
    }
    cout << coins << endl;
  }
  return 0;
}
