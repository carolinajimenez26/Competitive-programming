#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main(void) {
  int n, m, x, ans;
  map<int, int> cds; // cd, amount
  while (cin >> n >> m) {
    if (!n and !m) break;
    ans = 0;
    cds.clear();
    for (int i = 0; i < m + n; i++) {
      cin >> x;
      if (cds.count(x)) {
        cds[x] += 1;
      } else cds[x] = 1;
    }
    for (auto& e : cds) {
      if (e.second > 1) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
