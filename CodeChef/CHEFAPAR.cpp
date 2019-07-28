#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(int argc, char const *argv[]) {
  int t, n, ai, ans;
  bool flag;
  cin >> t;
  while (t--) {
    flag = false;
    ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> ai;
      if (!ai) {
        flag = true;
        ans += 1000;
      }
      if (flag) ans += 100;
    }
    cout << ans << endl;
  }
  return 0;
}
