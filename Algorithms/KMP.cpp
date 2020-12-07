// See https://www.youtube.com/watch?v=BXCEFAzhxGY&t=604s
#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

// Let n = s.size()
// Runtime: O(n^2)
// Space: O(n)
int GetPrefixSuffixCount(const string& s) {
  if (s.empty() || s.size() == 1) return 0;
  int size = s.size();
  int max_it = (size + 1) / 2;
  int substr_size = 1;
  int best = 0;
  while (substr_size <= max_it) {
    if (s.substr(0, substr_size) == s.substr(size - substr_size, substr_size)) {
      best = substr_size;
    }
    substr_size++;
  }
  return best;
}

// Let n = s.size()
// Runtime: O(n^3)
// Space: O(n)
vector<int> PrefixFuncitonSlow(const string& s) {
  vector<int> pi(s.size(), 0);
  string curr;
  for (int i = 0; i < s.size(); i++) {
    curr.push_back(s[i]);
    pi[i] = GetPrefixSuffixCount(curr);
  }
  return pi;
}

// Let n = s.size()
// Runtime: O(n)
// Space: O(n)
vector<int> PrefixFunciton(const string& s) {
  vector<int> pi(s.size(), 0);
  int i = 0, j = 1;
  while (j < s.size()) {
    if (s[i] != s[j]) {
      pi[j] = 0;
      j++;
    } else {
      while (j < s.size() && s[i] == s[j]) {
        pi[j] = i + 1;
        i++;
        j++;
      }
      // mismatch
      i = i - 1 >= 0? pi[i - 1] : 0;
    }
  }
  return pi;
}

// Let n = s.size(), m = pattern.size()
// Runtime: O(n + m)
// Space: O(m)
int Find(const string& s, const string& pattern) {
  vector<int> table = PrefixFunciton(pattern);
  int i = 0, j = 0;
  while (i < s.size() && j < pattern.size()) {
    while (i < s.size() && s[i] != pattern[j]) i++;
    while (i < s.size() && j < pattern.size() && s[i] == pattern[j]) {
      // matches
      i++;
      j++;
    }
    if (j >= pattern.size()) return i - j;
    j = table[j - 1];
  }
  return -1; // not found
}

struct Test {
  string s, pattern;
  int expected;
  vector<int> prefix_function;
};

bool TestPrefixFunction(const vector<Test>& tests) {
  cout << "Start testing PrefixFunction" << endl;
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    vector<int> out = PrefixFunciton(test.pattern);
    if (out != test.prefix_function) {
      cout << "Failed on test #" << tc << endl;
      cout << "Found:" << endl;
      Print(out);
      cout << "Expected:" << endl; 
      Print(test.prefix_function);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  cout << "End testing PrefixFunction" << endl;
  return succeed;
}

bool TestFind(const vector<Test>& tests) {
  cout << "Start testing Find" << endl;
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    int out = Find(test.s, test.pattern);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " 
           << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  cout << "End testing Find" << endl;
  return succeed;
}

int main(void) {
  vector<Test> tests = {
    { "abcaabcaabaaab", "aabaaab", 7, { 0,1,0,1,2,2,3 } },
    { "deadelephant", "deadeye", -1, { 0,0,0,1,2,0,0 } },
    { "deadeadeyelephant", "deadeye", 3, { 0,0,0,1,2,0,0 } },
    { "dedeadelephant", "dead", 2, { 0,0,0,1 } },
    { "deadelephant", "dead", 0, { 0,0,0,1 } },
    { "deadelephant", "de", 0, { 0,0 } },
    { "abcxbcabcd", "abcd", 6, { 0,0,0,0 } },
    { "", "abcd", -1, { 0,0,0,0 } },
    { "abcxbcabcd", "", -1, {} },
  };
  if (TestPrefixFunction(tests) && TestFind(tests)) {
    cout << "Good job!!" << endl;
  } else {
    cout << "Keep trying" << endl;
  }
  return 0;
}