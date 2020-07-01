#include <iostream>
using namespace std;

int HowManyMovesToFix(const string& s) {
  int opening = 0, ans = 0;
  for (auto c : s) {
    if (c == ')') {
      opening > 0 ? opening-- : ans++;
    } else {
      opening++;
    }
  }
  return ans;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << HowManyMovesToFix(s) << endl;
  }
  return 0;
}