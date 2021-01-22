#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  // Let n = word1.size()
  // Runtime: O(n log n)
  // Space: O(n)
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) {
      return false;
    }
    unordered_map<char, int> freqs_word1 = GetFreqs(word1); // O(n)
    unordered_map<char, int> freqs_word2 = GetFreqs(word2); // O(n)
    if (!HasSameKeys(freqs_word1, freqs_word2)) { // O(n)
      return false;
    }
    return HasSameValues(freqs_word1, freqs_word2); // O(n log n)
  }
private:
  unordered_map<char, int> GetFreqs(const string& s) {
    unordered_map<char, int> ans;
    for (auto letter : s) {
      ans[letter]++;
    }
    return ans;
  }

  bool HasSameKeys(const unordered_map<char, int>& a, 
                   const unordered_map<char, int>& b) {
    for (auto [key, _] : a) {
      if (b.count(key) == 0) {
        return false;
      }
    }
    return true;
  }

  vector<int> GetValues(const unordered_map<char, int>& hash_table) {
    vector<int> ans;
    for (auto [_, val] : hash_table) {
      ans.push_back(val);
    }
    sort(ans.begin(), ans.end());
    return ans;
  }

  bool HasSameValues(const unordered_map<char, int>& a, 
                     const unordered_map<char, int>& b) {
    return GetValues(a) == GetValues(b);
  }
};

struct Test {
  string word1, word2;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    { "abc", "bca", true },
    { "a", "aa", false },
    { "cabbba", "abbccc", true },
    { "cabbba", "aabbss", false },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.closeStrings(test.word1, test.word2);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}