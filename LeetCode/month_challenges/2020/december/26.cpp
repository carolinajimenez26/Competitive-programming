#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // Let n = s.size()
  // Runtime: O(n)
  // Space: O(n)
  int numDecodings(string s) {
    memo.assign(s.size(), -1);
    return NumDecodings(s, 0);
  }
private:
  vector<int> memo;

  bool CanBeDecoded(const string& s) {
    if (s.size() <= 0 || s.size() > 2) return false;
    if (s.size() > 1 && s[0] == '0') {
      return false;
    }
    int n = stoi(s);
    return n >= 1 && n <= 26;
  }
  // 3 -> 1
  // 23 -> 2
  // 223 -> 2 + 1 = 3
  int NumDecodings(const string& s, int idx) {
    if (idx >= s.size()) return 1;
    if (memo[idx] != -1) return memo[idx];
    int result = 0;
    string curr = string(1, s[idx]);
    if (CanBeDecoded(curr)) {
      result += NumDecodings(s, idx + 1);
    }
    if (idx + 1 < s.size()) {
      curr.push_back(s[idx + 1]);
      if (CanBeDecoded(curr)) {
        result += NumDecodings(s, idx + 2);
      }
    }
    memo[idx] = result;
    return result;
  }
};

struct Test {
  string s;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { "01", 0},
    { "2", 1 },
    { "22", 2 },
    { "223", 3 },
    { "2232", 3 },
    { "22321", 6 },
    { "223213", 9 },
    { "12", 2 },
    { "226", 3 },
    { "0", 0 },
    { "00", 0 },
    { "000", 0 },
    { "0001", 0 },
    { "1", 1 },
    { "111", 3 },
    { "10", 1 },
    { "100", 0 },
    { "11101202", 2},
    { "2202", 1 },
    { "111111111111111111111111111111111111111111111", 1836311903 },
    { "301", 0 },
    { "27", 1 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.numDecodings(test.s);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}