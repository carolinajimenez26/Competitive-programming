#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

void print(vector<bool> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void print(unordered_map<char, vector<int>> m) {
  for (auto& e : m) {
    cout << e.first << "->";
    for (auto i : e.second) cout << i << " ";
    cout << endl;
  }
  cout << endl;
}

unordered_map<char, vector<int>> getInfo(string s) {
  unordered_map<char, vector<int>> result;
  for (int i = 0; i < s.size(); i++) result[s[i]].push_back(i);
  return result;
}

string customSortString(string S, string T) { // O (S.size()) * O (T.size())
  string left = "";
  string right = "";
  vector<bool> used(T.size());
  unordered_map<char, vector<int>> T_info = getInfo(T); // O (T.size())
  // print(T_info);
  for (int i = 0; i < S.size(); i++) { // O (S.size())
    if (T_info.count(S[i])) {
      // dbg(S[i]);
      for (int j = 0; j < T_info[S[i]].size(); j++) { // O (T_info[S[i]].size()) => O (T.size())
        left.push_back(S[i]);
        used[ T_info[S[i]][j] ] = true;
        // print(used);
      }
    }
  }
  for (int i = 0; i < used.size(); i++) { // O (used.size()) = O (T.size())
    if (!used[i]) right.push_back(T[i]);
  }
  sort(right.begin(), right.end()); // O (log(right.size()))
  return (left += right);
}

string customSortString2(string S, string T) {
  unordered_map<char, int> index;
  for (int i = 0; i < S.size(); i++) {
    index[S[i]] = i;
  }
  sort(T.begin(), T.end(), [&index](char a, char b) {
    if (index.count(a) && index.count(b)) {
      return index[a] < index[b];
    }
    if (index.count(a)) return true;
    if (index.count(b)) return false;
    return a < b;
  });
  return T;
}

int main(void) {
  cout << customSortString("kqep","pekeq") << endl;
  cout << "Expected kqeep" << endl;
  return 0;
}
