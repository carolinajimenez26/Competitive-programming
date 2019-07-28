#include <bits/stdc++.h>
using namespace std;

int main (void) {
  vector<unsigned int> v;
  unsigned int x, ans;
  while (cin >> x) {
    v.push_back(x);
    if (x < v[v.size() - 2]) sort(v.begin(), v.end());
    if (v.size() % 2 == 0) {
      ans = (v[v.size() / 2] + v[(v.size() / 2) - 1] ) / 2;
    } else {
      ans = v[v.size() / 2];
    }
    cout << ans << endl;
  }
  return 0;
}
