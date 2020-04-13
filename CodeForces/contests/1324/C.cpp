#include <iostream>
#include <vector>
#define INF numeric_limits<int>::max()

using namespace std;

int main(void) {
  int tc;
  cin >> tc;
  string s;
  while (tc) {
    cin >> s;
    int res = 0, last_r = -1;
    s.push_back('R');
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R') {
        int distance = i - last_r;
        res = max(res, distance);
        last_r = i;
      }
    }
    res = (last_r == -1 ? s.size() + 1 : res);
    cout << res << endl;
    tc--;
  }
  return 0;
}