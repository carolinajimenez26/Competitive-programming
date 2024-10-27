#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


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