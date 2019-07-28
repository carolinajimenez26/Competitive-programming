#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

void print(unordered_map<char, int> m) {
  for (auto e : m) {
    cout << e.first << "->" << e.second << endl;
  }
  cout << endl;
}

void print(map<int, vector<char>> m) {
  for (auto e : m) {
    cout << e.first << "->";
    for (auto i : e.second) {
      cout << i << " ";
    }
    cout << endl;
  }
  cout << endl;
}

string frequencySort(string s) {
  unordered_map<char, int> frec;
  for (int i = 0; i < s.size(); i++) {
    if (frec.count(s[i])) {
      frec[s[i]] += 1;
    } else {
      frec[s[i]] = 1;
    }
  }

  // print(frec);

  map<int, vector<char>> frec_inverted;
  for (auto e : frec) {
    frec_inverted[e.second].push_back(e.first);
  }

  // print(frec_inverted);

  string result = "";

  for (auto it = frec_inverted.rbegin(); it != frec_inverted.rend(); ++it) {
    for (auto i : it->second) {
      for (int n = 0; n < it->first; n++) {
        result.push_back(i);
      }
    }
  }

  return result;
}

int main(void) {
  cout << frequencySort("tree") << endl;
  return 0;
}
