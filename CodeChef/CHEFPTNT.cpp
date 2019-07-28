#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main(void) {
  long int t, patents, months, patents_per_month, workers, odd, even, ans;
  string s;
  cin >> t;
  while (t--) {
    odd = even = 0;
    ans = 0;
    cin >> patents >> months >> patents_per_month >> workers >> s;
    for (int i = 0; i < s.size(); i++) {
      s[i] == 'E' ? even++ : odd++;
    }
    for (int i = 1; i <= months; i++) {
      if (i % 2) { // odd
        if (patents_per_month <= odd) {
          ans += patents_per_month;
          odd -= patents_per_month;
        } else {
          ans += odd;
          odd = 0;
        }
      } else { // even
        if (patents_per_month <= even) {
          ans += patents_per_month;
          even -= patents_per_month;
        } else {
          ans += even;
          even = 0;
        }
      }
      if (ans >= patents) break;
    }
    if (ans >= patents) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
