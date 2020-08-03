#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  bool IsNumber(const char c) {
    return c >= '0' && c <= '9';
  }

  bool IsLetter(const char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

  string Normalize(const string& s) {
    string ans;
    for (auto c : s) {
      if (IsLetter(c)) {
        ans.push_back(tolower(c));
      }
      if (IsNumber(c)) {
        ans.push_back(c);
      }
    }
    return ans;
  }
public:
  bool isPalindrome(string s) {
    if (s.empty()) return true;
    // dbg("---"); dbg(s);
    s = Normalize(s);
    // dbg(s);
    for (int i = 0, j = s.size() - 1; i < s.size() && i < j; i++, j--) {
      if (s[i] != s[j]) return false;
    }
    return true;
  }
};

struct Test {
  string s;
  bool ans;
};

int main(void) {
  vector<Test> tests = {
    { "12A man, a plan, a canal: Panama21!!", true },
    { "12A man, a plan, a canal: Panama21", true },
    { "12A man, a plan, a canal: Panama", false },
    { "A man, a plan, a canal: Panama", true },
    { "", true },
    { "race a car", false },
  };

  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    bool out = sol.isPalindrome(test.s);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}