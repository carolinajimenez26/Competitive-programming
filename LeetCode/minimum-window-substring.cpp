#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

/*
s1 = aaaabbbcccab
s2 = aabbcc

t = abc

a->3
b->2
c->2

a

*/

struct Counter {
  unordered_map<char, int> freqs;
  int counter;
  Counter(string s) {
    counter = 0;
    for (auto c : s) {
      freqs[c]++;
    }
  }

  bool ContainsAllLetters() {
    return counter == freqs.size();
  }

  void Decrement(char c) {
    if (freqs.count(c) == 0) return;
    freqs[c]--; // uses the letter
    if (freqs[c] == 0) counter++; // if we use all the letters
  }

  void Increment(char c) { // stops using the letter
    if (freqs.count(c) == 0) return;
    bool was_zero = false;
    if (freqs[c] == 0) was_zero = true;
    freqs[c]++;
    if (was_zero) counter--;
  }

  void Print() {
    for (auto e : freqs) {
      cout << e.first << " -> " << e.second << endl;
    }
    cout << endl;
  }
};

class Solution {
public:
  void print(unordered_map<char, int>& info) {
    for (auto e : info) {
      cout << e.first << " -> " << e.second << endl;
    }
    cout << endl;
  }

  bool Validate(unordered_map<char, int>& info, const string& t) {
    for (auto e : t) {
      if (info[e] <= 0) {
        return false;
      }
    }
    return true;
  }

  void FindValidSolution(const string &str, Counter& counter, int& right) {
    while (right < str.size()) {
      counter.Decrement(str[right]);
      if (counter.ContainsAllLetters()) {
        break;
      }
      right++;
    }
  }

  pair<int, int> FindMinimumSolution(const string& str, Counter& counter, int& left, int& right) {
    pair<int, int> result_indexes = {-1,-2};
    int result = str.size() + 10;
    while (left <= right) {
      if (counter.ContainsAllLetters()) {
        int curr_result = right - left + 1;
        if (curr_result < result) {
          result = curr_result;
          result_indexes = {left, right};
        }
        counter.Increment(str[left]); // try to find another answer
        left++;
      } else {
        right++;
        break;
      }
    }
    return result_indexes;
  }

  string CreateString(string s, int start, int end) {
    if (end < start) return "";
    return s.substr(start, end - start + 1);
  }

  string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";
    Counter counter(t);
    pair<int, int> result_indexes = {-1,-2};
    int result = s.size() + 10;
    int left = 0, right = 0;
    
    // O (arr.size() * )
    while (left <= right && right < s.size()) { // O (s.size())
      FindValidSolution(s, counter, right); // increases j until it find a valid solution
      pair<int, int> curr_result_indexes = FindMinimumSolution(s, counter, left, right); // increases i until there is a solution
      if (curr_result_indexes.first != -1) {
        int curr_result = curr_result_indexes.second - curr_result_indexes.first + 1;
        if (curr_result < result) {
          result = curr_result;
          result_indexes = curr_result_indexes;
        }
      }
    }
    return CreateString(s, result_indexes.first, result_indexes.second);
  }
};

struct Test {
  string t;
  string s;
  string expected;
};

int main(void) {
  vector<Test> tests = {
    {
      "ABC",
      "ADOBECODEBANC",
      "BANC"
    },
    {
      "aa",
      "a",
      ""
    },
    { 
      "aa",
      "aa",
      "aa"
    },
    {
      "xyz",
      "xyyzyzyx",
      "zyx"
    }
  };

  bool succeed = true;
  int i = 0;
  for (auto test : tests) {
    Solution sol;
    string output = sol.minWindow(test.s, test.t);
    if (output != test.expected) {
      succeed = false;
      cout << "Failed on test #" << i << endl;
      cout << "Expected " << test.expected << " received " << output << endl;
    }
    i++;
  }

  if (succeed) cout  << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}

