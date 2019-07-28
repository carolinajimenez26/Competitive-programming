#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define INF numeric_limits<int>::max()

int main(void) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  long long a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    bitset<64> n(a);
    bitset<64> m(b);
    cout << (n.count() + m.count()) << endl;
  }
  return 0;
}
