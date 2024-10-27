#include <iostream>
#include <unordered_set>
#include <algorithm> 
#include <vector>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl


class Solution {
  // Let n = s.size()
private:
  // O (10)
  char GetSmallerValue(char c, int delta) {
    int n = c - '0';
    int smaller = n;
    for (int i = 0; i < 10; i++) {
      n = (n + delta) % 10;
      smaller = min(smaller, n);
    }
    char result = smaller + '0';
    return result;
  }

  // n * 10
  void SetSmallers(string& s, int delta) {
    for (int i = 0; i < s.size(); i++) {
      if (i % 2 == 0) {
        continue;
      }
      char smaller = GetSmallerValue(s[i], delta);
      s[i] = smaller;
    }
  }

  // O (n)
  string GetSmaller(const unordered_set<string>& posibilities) {
    string result;
    if (posibilities.empty()) {
      return result;
    }
    for (auto s : posibilities) {
      if (result == "") {
        result = s;
      }
      if (s < result) {
        result = s;
      }
    }
    return result;
  }

  void Print(const unordered_set<string>& hash_table) {
    for (auto s : hash_table) {
      cout << s << ", ";
    }
    cout << endl;
  }

public:
  string findLexSmallestString(string s, int a, int b) {
    unordered_set<string> posibilities;
    // O (n * n)
    while (true) {
      SetSmallers(s, a); // O (n)
      if (posibilities.count(s) > 0) { // O (n)
        break;
      }
      posibilities.insert(s); // O (n)
      rotate(s.begin(), s.begin() + b, s.end()); // O (b) --> O (n)
    }
    Print(posibilities);
    return GetSmaller(posibilities);
  }
};

/*

s = "3456", a = 5, b = 2

3 + 5 = 8 + 5 = 3
5 + 5 = 0 + 5 = 5
6 + 5 = 1 + 5 = 6

movements:

1) 3456 --> 6435
2) 3456 --> 5634
3) 3456 --> 4563
4) 3456 --> 3456

1) 34567 --> 73456
2) 34567 --> 67345
4) 34567 --> 


s = "5525", a = 9, b = 2

5: 5 + 9 = 4 + 5 = 9 + 5 = 4
2: 2 + 9 = 1 + 9 = 0 
9: 9 + 9 = 8 + 9 = 7 + 9 = 6 ... 1 + 9 = 0

*/

struct Test {
  string s;
  int a, b;
  string expected;
};

int main(void) {
  vector<Test> tests = {
    // { "5525", 9, 2, "2050" },
    // { "74", 5, 1, "24" },
    // { "0011", 4, 2, "0011" },
    { "43987654", 7, 3, "00553311" },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    string out = sol.findLexSmallestString(test.s, test.a, test.b);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;

  return 0;
}