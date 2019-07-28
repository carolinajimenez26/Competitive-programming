#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int tc, letters, value, lines;
  double total = 0;
  char letter;
  string line;
  cin >> tc;
  unordered_map<char, int> m;
  while (tc--) {
    total = 0;
    cin >> letters;
    for (int i = 0; i < letters; i++) {
      cin >> letter;
      cin >> value;
      m[letter] = value;
    }
    cin >> lines;
    lines++;
    while (lines--) {
      getline(cin, line);
      for (int i = 0; i < line.length(); i++) {
        if (m.count(line[i])) {
          total += m[line[i]];
        }
      }
    }
    cout << fixed << setprecision(2) << total / 100 << "$" << endl;
    m.clear();
  }
  return 0;
}
