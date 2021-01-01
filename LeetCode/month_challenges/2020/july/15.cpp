#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  void MoveChars(string& s, int& write_pos, int from, int to) {
    for (int i = from; i <= to && i < s.size(); i++, write_pos++) {
      if (i == write_pos) continue;
      s[write_pos] = s[i];
      s[i] = ' ';
    }
  }

  void Normalize(string& s) {
    int reader = 0, writer = 0;
    while (reader < s.size()) {
      while (reader < s.size() && s[reader] == ' ') {
        reader++;
      }
      int from = reader;
      while (reader < s.size() && s[reader] != ' ') {
        reader++;
      }
      int to = reader - 1;
      MoveChars(s, writer, from, to);
      if (reader == s.size()) {
        break;
      }
      if (writer != s.size()) {
        s[writer] = ' ';
      }
      writer++;
    }
    for (int i = s.size() - 1; i >= 0 && s[i] == ' '; i--) {
      s.pop_back();
    }
  }

  void Reverse(string& s, int from, int to) {
    for (int i = from, j = to; i <= to && j > i; i++, j--) {
      char tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
    }
  }

public:
  string reverseWords(string s) {
    Normalize(s);
    if (s.empty()) return "";
    Reverse(s, 0, s.size() - 1);
    int i = 0;
    while (i < s.size()) {
      int j;
      for (j = i; j < s.size() && s[j] != ' '; j++) {}
      Reverse(s, i, j - 1);
      i = j + 1;
    }
    return s;
  }
};

struct Test {
  string s, ans;
};

int main(void) {
  vector<Test> tests = {
    { "the sky is blue", "blue is sky the" },
    { "  hello world!  ", "world! hello" },
    { "a good   example", "example good a" },
    { "", "" },
    { "   ", "" },
    { "a  b c d  ", "d c b a" }
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    string out = sol.reverseWords(test.s);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found: " << out << ", expected: " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}