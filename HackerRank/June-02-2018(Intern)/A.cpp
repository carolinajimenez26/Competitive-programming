#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// #define dbg(x) cout << #x << ": " << x << endl
// #define INF numeric_limits<int>::max()

int main(void) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int n;
  string s, love = "love";
  cin >> n;
  while (n--) {
    cin >> s;
    int sum = 0, ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'l') {
        for (int j = 0; j < 4 and j < s.size(); j++) {
          if(s[i + j] == love[j]) sum++;
        }
        if (sum == 4) ans++;
        sum = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
