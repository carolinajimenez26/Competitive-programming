#include <iostream>
using namespace std;

void Put(string& result, string sub, int times) {
  while (times--) {
    for (auto c : sub) {
      result.push_back(c);
    }
  }
}

int main(void) {
  int tc;
  string t;
  cin >> tc;
  while (tc--) {
    cin >> t;
    string s = "";
    int zeros, ones;
    zeros = ones = 0;
    for (auto e : t) {
      if (e == '0') zeros++;
      else ones++;
    }
    if (zeros == 0 || ones == 0) {
      cout << t << endl;
      continue;
    }
    char curr = t[0];
    int count = 0;
    for (int i = 0; i < t.size();) {
      while (i < t.size() && t[i] == curr) {
        count++;
        i++;
      }
      if (curr == '1') {
        Put(s, "10", count);
        s.pop_back();
      } else {
        Put(s, "01", count);
        s.pop_back();
      }
      count = 0;
      curr = i < t.size() ? t[i] : 'x';
    }
    cout << s << endl;
  }
  return 0;
}