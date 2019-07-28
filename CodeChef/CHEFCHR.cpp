#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void find(string s) {
  bool lovely = false;
  int n = 0;
  bitset<4> chef;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i, count = 0; j < s.size() and count < 4; j++, count++) {
      if (s[j] == 'c') chef[0] = 1;
      if (s[j] == 'h') chef[1] = 1;
      if (s[j] == 'e') chef[2] = 1;
      if (s[j] == 'f') chef[3] = 1;
    }
    if (chef.all()) n++, lovely = true;
    chef.reset();
  }
  if (lovely) cout << "lovely " << n << endl;
  else cout << "normal" << endl;
}

int main(void) {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    find(s);
  }
  return 0;
}
