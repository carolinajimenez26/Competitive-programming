#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


bool simulate(string sequence, string &source, string &target, bool complete) {
  string tmp = "";
  int i = 0, j = 0, size = sequence.size();
  // if (size != 2 * source.size())
  //   return false;
  stack<char> st;
  while (size--) {
    if (sequence[i] == 'i')
      st.push(source[j++]);
    else {
      if (st.empty()) return false;
      tmp.push_back(st.top());
      st.pop();
      int k = tmp.size() - 1;
      if (tmp[k] != target[k])
        return false;
    }
    i++;
  }
  return complete ? j == target.size() : true;
}

void anagram(string sequence, string &source, string &target, vector<string> &ans) {
  if (sequence.size() > 2 * target.size()) return;
  if (simulate(sequence, source, target, false)) {
    // dbg(sequence);
    if (sequence.size() == 2 * target.size() and simulate(sequence, source, target, true))
      ans.push_back(sequence);
    else {
      anagram(sequence + "i", source, target, ans);
      anagram(sequence + "o", source, target, ans);
    }
  }
}

void print(vector<string> v) {
  cout << "[" << endl;
  for(auto& e : v) {
    for (int i = 0; i < int(e.size()); i++) {
      if (i) cout << " ";
      cout << e[i];
    }
    cout << endl;
  }
  cout << "]" << endl;
}

int main(void) {
  string source, target;
  while (cin >> source) {
    cin >> target;
    vector<string> ans;
    string sequence = "";
    anagram(sequence, source, target, ans);
    print(ans);
  }
  return 0;
}
