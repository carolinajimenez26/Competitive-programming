#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  void Print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }
public:
  // Let n = s.size()
  // Runtime: O(n)
  // Space: O(n) 
  int minimumDeletions(string s) {
    if (s.empty()) return 0;
    vector<int> a_count(s.size(), 0), b_count(s.size(), 0);
    a_count[0] = (s[0] == 'a');
    b_count[0] = (s[0] == 'b');
    for (int i = 1; i < s.size(); i++) {
      a_count[i] += (a_count[i - 1] + (s[i] == 'a'));
      b_count[i] += (b_count[i - 1] + (s[i] == 'b'));
    }
    // Print(a_count);
    // Print(b_count);
    vector<int> costs(s.size(), 0);
    bool is_valid = true, b_appeared = false;
    for (int i = 0; i < costs.size(); i++) {
      if (s[i] == 'b') b_appeared = true;
      if (s[i] == 'a' && b_appeared) is_valid = false;
      if (is_valid) {
        if (s[i] == 'a') {
          costs[i] += b_count.back() - b_count[i]; // remove all b occurrances after this one
        } else {
          costs[i] += a_count.back() - a_count[i]; // remove all a occurrances after this one
        }
      } else {
        costs[i] += a_count.back() - a_count[i]; // remove all a occurrances after this one
        costs[i] += b_count[i]; // remove all b occurrances before this one
      }
    }
    // Print(costs);
    return *min_element(costs.begin(), costs.end());
  }
};

struct Test {
  string s;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { "aababbab", 2 },
    { "bbaaaaabb", 2 },
    { "aaabbab", 1 },
    { "aaabbb", 0 },
    { "", 0 },
    { "a", 0 },
    { "ab", 0 },
    { "ba", 1 },
    { "bbbbaa", 2 },
    { "bbbaaaa", 3 },
    { "baababbaabbaaabaabbabbbabaaaaaabaabababaaababbb", 18},
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.minimumDeletions(test.s);
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