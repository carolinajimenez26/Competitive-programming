#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int i = 0, v_i = 0;
    int j = 0, v_j = 0;
    while (v_i < word1.size() && v_j < word2.size()) {
      if (i >= word1[v_i].size()) {
        v_i++;
        i = 0;
      }
      if (j >= word2[v_j].size()) {
        v_j++;
        j = 0;
      }
      if (v_i >= word1.size() || v_j >= word2.size()) {
        break;
      }
      if (word1[v_i][i] != word2[v_j][j]) {
        return false;
      }
      i++; j++;
    }
    return (v_i == word1.size() && v_j == word2.size());
  }
};

struct Test {
  vector<string> word1, word2;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    { {"ab", "c"}, {"a", "bc"}, true },
    { {"a", "cb"}, {"ab", "c"}, false },
    { {"abc", "d", "defg"}, {"abcddefg"}, true },
    { {"a", "d", "d"}, {"a","d"}, false },
    { {}, {}, true },
    { {}, {"a"}, false },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.arrayStringsAreEqual(test.word1, test.word2);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}