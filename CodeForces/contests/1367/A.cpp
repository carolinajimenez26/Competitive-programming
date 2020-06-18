#include <iostream>
using namespace std;

string GetOriginal(const string& s) {
  string ans = "";
  if (s.size() == 2) return s;
  for (int i = 0; i < s.size(); i += 2) {
    ans.push_back(s[i]);
  }
  ans.push_back(s.back());
  return ans;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    string b;
    cin >> b;
    cout << GetOriginal(b) << endl;
  }
}