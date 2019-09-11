#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isSubsequence(const string& s, const string& t, int idx_s, int idx_t) {
    if (idx_s >= s.size()) {
      return true;
    }
    if (idx_t >= t.size()) {
      return false;
    }
    if (s[idx_s] == t[idx_t]) {
      idx_s++;
    }
    return isSubsequence(s, t, idx_s, idx_t + 1);
  }

  bool isSubsequence(string s, string t) {
    if (s.size() > t.size()) return false;
    return isSubsequenceIterative(s, t);
  }
};

int main(void) {
  // string s = "abc", t = "ahbgdc";
  string s = "axc", t = "ahbgdc";
  Solution sol;
  cout << sol.isSubsequence(s, t) << endl;
  return 0;
}
