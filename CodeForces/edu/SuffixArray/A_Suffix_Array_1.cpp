#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Element {
  int idx;
  string s;

  bool operator<(const Element& other) {
    return s < other.s;
  }
}

// v will be of size 2^(k - 1)
vector<Element> Create(const vector<Element>& v, const int k, const string& ori) {
  vector<Element> ans;
  for (auto e : v) {
    string s = e.s.size();
    int i = (e.idx + s) % ori.size();
    for (int curr_size = e.s.size(); curr_size < k; curr_size++) {
      s.push_back(ori[(i + 1) % ori.size()]);
    }
    ans.push_back({e.idx,s});
  }
  return ans;
}

vector<int> GetSuffixArray(const string& ori) {
  string s = ori;
  s.push_back('$');

  // --------- k = 0 --------- 
  vector<Element> curr;
  for (int i = 0; i < s.size(); i++) {
    curr.push_back(i, s[i]);
  }
  sort(curr.begin(), curr.end());

  unordered_map<string, int> equivalence;
  equivalence[curr[0].s] = curr[0].idx;
  for (int i = 1; i < curr.size(); i++) {
    int last_val = equivalence[curr[i - 1].s];
    equivalence[curr[i].s] = (curr[i].s == curr[i - 1].s ? last_val : last_val + 1);
  }

  // ---------  k = 1 ... k = log2(s.size()) --------- 
  int max_k = ceil(log2(s.size()));
  for (int k = 1, n = 1; k < max_k; k++, n <<= 1) {
    curr = Create(curr, n, s.size()); // strings of size 2^k
    Sort(curr, equivalence);
  }
}

void Print(const vector<int>& v) {
  for (auto i : v) cout << i << " ";
  cout << endl;
}

int main(void) {
  string s;
  cin >> s;
  vector<int> sufix_array = GetSuffixArray(s);
  Print(sufix_array);
  return 0;
}