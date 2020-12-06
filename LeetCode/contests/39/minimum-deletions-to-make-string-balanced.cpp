#include <iostream>
#include <vector>
using namespace std;

struct PrefixSum {
  vector<int> sum;

  PrefixSum(const string& s, char c) {
    sum.assign(s.size(), 0);
    sum[0] = (s[0] == c);
    for (int i = 1; i < sum.size(); i++) {
      int plus = (s[i] == c);
      sum[i] = (sum[i - 1] + plus); 
    }
  }

  int Get(int from, int to) {
    if (from > to) return 0;
    if (from == 0) return sum[to];
    return sum[to] - sum[from - 1];
  }

  void Print() {
    for (auto e : sum) cout << e << " ";
    cout << endl;
  }
};

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
    PrefixSum a_count(s, 'a');
    // a_count.Print();
    PrefixSum b_count(s, 'b');
    // b_count.Print();
    vector<int> costs(s.size(), 0);
    for (int i = 0; i < costs.size(); i++) {
      costs[i] += a_count.Get(i + 1, s.size() - 1);
      costs[i] += b_count.Get(0, i);
    }
    // Print(costs);
    int best = *min_element(costs.begin(), costs.end()); // make it balance
    best = min(best, a_count.Get(0, s.size() - 1)); // keep all b's
    best = min(best, b_count.Get(0, s.size() - 1)); // keep all a's
    return best;
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