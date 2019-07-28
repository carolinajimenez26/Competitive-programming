#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


void print(map<char, pair<int, vector<int>> > m) {
  for (auto& e : m) {
    cout << e.first << "->" << e.second.first << " , ";
    for (auto& i : e.second.second) cout << i << " ";
    cout << endl;
  }
}

void print(vector<int> v) {
  for (auto& e : v) cout << (e + 1) << " ";
  cout << endl;
}

void print(vector<char> v) {
  for (auto& e : v) cout << e;
  cout << endl;
}

bool isPalindrome(map<char, pair<int, vector<int>> > m, int &amount, char &letter) {
  int tmp = 0;
  for (auto& e : m) {
    if (e.second.first % 2 != 0) {
      tmp++;
      amount = e.second.first;
      letter = e.first;
    }
    if (tmp > 1) return false;
  }
  return true;
}

void createPalindrome(map<char, pair<int, vector<int>> > m, string s, char letter) {
  vector<int> v(s.size());
  vector<char> pal(s.size());
  int i = 0, j = v.size() - 1;
  for (auto e : m) {
    if (e.first != letter) {
      for (int k = 0; k < e.second.second.size(); k += 2, i++, j--) {
        v[i] = e.second.second[k];
        v[j] = e.second.second[k + 1];
        pal[i] = e.first;
        pal[j] = e.first;
      }
    }
  }

  for (int k = 0; k < m[letter].second.size(); k++, i++) {
    v[i] = m[letter].second[k];
    pal[i] = letter;
  }

  print(v);
  // print(pal);
}

map<char, pair<int, vector<int>> > getFrecuencies(string s) {
  map<char, pair<int, vector<int>> > m;
  for (int i = 0; i < s.size(); i++) {
    if (m.count(s[i])) {
      m[s[i]].first += 1;
      m[s[i]].second.push_back(i);
    } else {
      m[s[i]].first = 1;
      m[s[i]].second.push_back(i);
    }
  }
  return m;
}

int main(void) {
  int t, amount;
  char letter;
  string s;
  bool pal;
  cin >> t;
  while (t--) {
    pal = false;
    cin >> s;
    map<char, pair<int, vector<int>> > frecuencies = getFrecuencies(s); // letter, times of appearence and index in the string
    // print(frecuencies);
    if (isPalindrome(frecuencies, amount, letter)) {
      createPalindrome(frecuencies, s, letter);
    } else cout << "-1" << endl;
  }
  return 0;
}
