#include <iostream>
#include <string>
#include <set>

using namespace std;

int memo[1234][1234];

bool isPalindrom(const string& s, int start, int end) {
    if (end <= start) {
      return true;
    }
    if (memo[start][end] == -1) {
      memo[start][end] = ((s[start] == s[end]) && isPalindrom(s, start + 1, end - 1));
    }
    return memo[start][end];
}

int countSubstrings(string s) {
  int total = 0;
  memset(memo, -1, sizeof memo);

  for (int start = 0; start < s.size(); start++) {
    for (int end = start; end < s.size(); end++) {
      if (isPalindrom(s, start, end)) {
        total++;
      }
    }
  }
  return total;
}

int main(void) {
  cout << countSubstrings("aabbccbbaa") << endl;
  return 0;
}
