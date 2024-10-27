#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
  unordered_set<char> allowed_set;

  bool IsValid(const string& word) {
    for (auto letter : word) {
      if (allowed_set.count(letter) == 0) return false;
    }
    return true;
  }

public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    if (allowed.empty() || words.empty()) return 0;
    for (auto letter : allowed) allowed_set.insert(letter);
    int ans = 0;
    for (auto word : words) {
      if (IsValid(word)) {
        ans++;
      }
    }
    return ans;
  }
};

struct Test {
  string allowed;
  vector<string> words;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { "ab", {"ad","bd","aaab","baa","badab"}, 2 },
    { "abc", {"a","b","c","ab","ac","bc","abc"}, 7 },
    { "cad", {"cc","acd","b","ba","bac","bad","ac","d"}, 4 },
    { "", {"cc","acd","b","ba","bac","bad","ac","d"}, 0 },
    { "cad", {"cc"}, 1 },
    { "cad", {}, 0 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.countConsistentStrings(test.allowed, test.words);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}