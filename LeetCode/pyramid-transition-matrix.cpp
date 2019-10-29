#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
  vector<string> allowed;

  vector<string> GetPosibilities(const string& s) {
    vector<string> result;
    for (auto e : allowed) {
      if (e[0] == s[0] && e[1] == s[1]) { // If it has the same prefix
        result.push_back(e);
      }
    }
    return result;
  }
  // (bottom.size() * (bottom.size() + 1) / 2) ^ bottom.size()
  bool pyramidTransition(string bottom, int idx_bottom, string new_bottom) {
    if (bottom.size() == 1) {
      return true;
    }
    if (idx_bottom == bottom.size() - 1) {
      bottom = new_bottom;
      new_bottom = "";
      return pyramidTransition(bottom, 0, new_bottom);
    }
    string curr;
    curr.push_back(bottom[idx_bottom]);
    curr.push_back(bottom[idx_bottom + 1]);
    vector<string> posibilities = GetPosibilities(curr);
    if (posibilities.empty()) return false;
    for (auto s : posibilities) {
      char c = s[2];
      new_bottom.push_back(c);
      if (pyramidTransition(bottom, idx_bottom + 1, new_bottom)) {
        return true;
      }
      new_bottom.pop_back();
    }
    return false;
  }
public:
  bool pyramidTransition(string bottom, vector<string>& allowed_) {
    allowed = allowed_;
    string s;
    return pyramidTransition(bottom, 0, s);
  }
};

struct Test {
  vector<string> allowed;
  string bottom;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {"BCG", "CDE", "GEA", "FFF"},
      "BCD",
      true
    },
    {
      {"AAA", "AAB", "ABA", "ABB", "BAC"},
      "AABA",
      false
    },
    {
      {"AAA", "AAB", "ABA", "ABB", "BAC", "ACA"},
      "AABA",
      true
    }
  };
  bool succeed = true;
  int tc = 0;
  for (auto test : tests) {
    Solution sol;
    if (sol.pyramidTransition(test.bottom, test.allowed) != test.expected) {
      cout << "Failed on test #" << tc << endl;
      succeed = false;
    }
    tc++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}