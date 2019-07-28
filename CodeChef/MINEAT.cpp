#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define N 100001
long int bannanas[N];

int myceil(long double n) {
  long int y = n;
  long double x = n - y;
  if (x > 0) return y + 1;
  return y;
}

int main(void) {
  int t;
  long int n, h, min_n, max_n, k, tmp, i;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    min_n = numeric_limits<long int>::max();
    max_n = numeric_limits<long int>::min();
    for (i = 0; i < n; i++) {
      cin >> bannanas[i];
      if (bannanas[i] > max_n) max_n = bannanas[i];
      if (bannanas[i] < min_n) min_n = bannanas[i];
    }
    i = 0;
    for (k = 1; k < N; k++) {
      if (i == n and tmp <= h) break;
      tmp = 0;
      for (i = 0; i < n; i++) {
        tmp += myceil(bannanas[i] / double(k));
        if (tmp > h) break;
      }
    }
    cout << (--k) << endl;
  }
  return 0;
}
