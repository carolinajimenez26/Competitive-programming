#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
  int a, b, tc, tmp;
  cin >> tc;
  while (tc--) {
    cin >> a >> b;
    tmp = ((a * log10(2)) + (b * log10(5))) + 1;
    cout << tmp << endl;
  }
  return 0;
}
