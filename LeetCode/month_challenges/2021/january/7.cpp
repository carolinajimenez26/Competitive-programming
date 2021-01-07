#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s_) {
    s = s_;
    if (s.empty() || s.size() == 1) {
      return s.size();
    }
    int best = 1;
    int left = 0, right = 0;
    while (right < s.size()) {
      seen.insert(s[left]);
      right++;
      right = MoveRightWhileUniques(right);
      best = max(best, right - left);
      if (right >= s.size()) {
        break;
      }
      left = MoveRightUntilRemoveChar(left, right - 1, s[right]);
      seen.insert(s[right]);
    }
    return best;
  }
private:
  unordered_set<int> seen;
  string s;

  int MoveRightWhileUniques(int right) {
    while (right < s.size() && seen.count(s[right]) == 0) {
      seen.insert(s[right]);
      right++;
    }
    return right;
  }

  int MoveRightUntilRemoveChar(int from, int to, char c) {
    int i = from;
    while (i <= to && s[i] != c) {
      seen.erase(s[i]);
      i++;
    }
    while (i <= to && s[i] == c) {
      seen.erase(s[i]);
      i++;
    }
    return i;
  }
};

struct Test {
  string s;
  int expected;
};

int main(void) {
  vector<Test> tests = { 
    { "abcabcbb", 3 },
    { "aaaaaaa", 1 },
    { "pwwkew", 3 },
    { "abxyzijkl", 9 },
    { "abba", 2 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.lengthOfLongestSubstring(test.s);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}
