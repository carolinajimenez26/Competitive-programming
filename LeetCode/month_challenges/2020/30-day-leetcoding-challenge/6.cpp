#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> order;
    vector<vector<string>> result;
    for (auto s : strs) {
      string s_copy = s;
      sort(s_copy.begin(), s_copy.end());
      order[s_copy].push_back(s);
    }
    for (auto e : order) {
      result.push_back(e.second);
    }
    return result;
  }
};

void print(vector<vector<string>>& vvs) {
  for (auto vs : vvs) {
    for (auto s : vs) cout << s << ",";
    cout << endl;
  }
}

int main(void) {
  vector<string> in = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution sol;
  vector<vector<string>> out = sol.groupAnagrams(in);
  print(out);
  return 0;
}