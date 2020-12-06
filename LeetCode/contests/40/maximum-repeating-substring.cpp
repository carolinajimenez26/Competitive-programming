#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

class Solution {
private:
  bool Contains(const string& sequence, int from, const string& word) {
    for (int j = 0; j < word.size(); j++, from++) {
      if (from >= sequence.size() || sequence[from] != word[j]) 
        return false;
    }
    return true;
  }
public:
  // Let n = sequence.size(), m = word.size()
  // Runtime: O(n * m)
  // Space: O(1)
  int maxRepeating(string sequence, string word) {
    if (sequence.empty() || word.empty()) return 0;
    int count = 0, best = 0;
    int i = 0;
    while (i < sequence.size()) {
      while (Contains(sequence, i, word)) {
        count++;
        i += word.size();
      }
      best = max(best, count);
      count = 0;
      i++;
    }
    return best;
  }
};

struct Test {
  string word, sequence;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { "ababc", "ab", 2},
    { "ababc", "ba", 1},
    { "ababc", "ac", 0},
    { "ababac", "aba", 1},
    { "abaab", "aba", 1},
    { "abc", "ca", 0},
    {"baba", "b", 1},
    {"bacaaaacabcaccccaacbcccccbcaaaacaabbaabbcababacca", "ac", 1},
    {"xacxacxac", "ac", 1},
    {"acaac", "ac", 1},
    {"abcdeabcdeabcde", "abcdx", 0},
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.maxRepeating(test.word, test.sequence);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out 
           << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}