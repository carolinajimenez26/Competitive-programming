#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

void Print(const vector<string>& vs) {
  for (auto s : vs) cout << s << " ";
}

void Print(const map<int, vector<string>>& m) {
  for (auto [key, val] : m) {
    cout << key << " -> ";
    Print(val);
    cout << endl;
  }
}

class Solution {
public:
  // Let s = sum of all word sizes
  // Let n = amount of words
  // Let m = longest word
  // let k be the size of the result
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freqs;
    for (auto word : words) { // O (s)
      freqs[word]++;
    }
    map<int, vector<string>> freqs_inverted;
    for (auto [word, amount] : freqs) { // O (n * log(n))
      freqs_inverted[amount].push_back(word);
    }
    // Print(freqs_inverted);
    vector<string> result;
    
    // O (k^2 * m * log(k))
    for (auto it = freqs_inverted.rbegin(); it != freqs_inverted.rend() && k > 0; it++) {
      auto [curr_freq, curr_words] = *it;
      sort(curr_words.begin(), curr_words.end()); // O (m * k * log k)
      for (int i = 0; i < curr_words.size() && k > 0; i++, k--) {
        result.push_back(curr_words[i]);
      }
    }
    return result;
  }
};

int main(void) {
  vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
  int k = 3;
  Solution sol;
  vector<string> top_k_frequent = sol.topKFrequent(words, k);
  Print(top_k_frequent);
  return 0;
}