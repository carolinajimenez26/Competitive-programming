#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

void print(unordered_map<char,vector<char>> m) {
  for (auto& e : m) {
    cout << e.first << " -> ";
    for (auto& child : e.second) {
      cout << child << " ";
    }
    cout << endl;
  }
  cout << endl;
}

unordered_map<char,vector<char>> split(string &s) {
  stringstream ss;
  ss << s;
  unordered_map<char,vector<char>> m;
  string tok;
  while (ss >> tok) {
    m[tok[1]].push_back(tok[0]);
  }
  return m;
}

string findMax(int sizes[4]) {
  int max = numeric_limits<int>::max() * -1;
  int max_index = -1;
  for (int i = 0; i < 4; i++) {
    if (sizes[i] > max) {
      max = sizes[i];
      max_index = i;
    }
  }
  if (max_index == 0) return "BID S";
  if (max_index == 1) return "BID H";
  if (max_index == 2) return "BID D";
  if (max_index == 3) return "BID C";
}

string getAns(unordered_map<char,vector<char>> m) {
  int ans = 0, no_trump = 0;
  int sizes[4] = {0,0,0,0};
  bool stop_S = false, stop_H = false, stop_D = false, stop_C = false;

  if (m.size() != 4) ans += (4 - m.size()) * 2;

  for (auto& e : m) {

    if (e.first == 'S') sizes[0] = e.second.size();
    if (e.first == 'H') sizes[1] = e.second.size();
    if (e.first == 'D') sizes[2] = e.second.size();
    if (e.first == 'C') sizes[3] = e.second.size();

    if (e.second.size() == 2) ans += 1;
    if (e.second.size() == 1) ans += 2;

    for (auto& child : e.second) {
      if (child == 'A') {
        ans += 4;
        no_trump += 4;
        if (e.first == 'S') stop_S = true;
        if (e.first == 'H') stop_H = true;
        if (e.first == 'D') stop_D = true;
        if (e.first == 'C') stop_C = true;
      }
      if (child == 'K') {
        ans += 3;
        no_trump += 3;
        if (e.second.size() == 1) {
          ans--;
          no_trump--;
        }
        if (e.second.size() > 1) {
          if (e.first == 'S') stop_S = true;
          if (e.first == 'H') stop_H = true;
          if (e.first == 'D') stop_D = true;
          if (e.first == 'C') stop_C = true;
        }
      }
      if (child == 'Q') {
        ans += 2;
        no_trump += 2;
        if (e.second.size() == 1 or e.second.size() == 2) {
          ans--;
          no_trump--;
        }
        if (e.second.size() >= 3) {
          if (e.first == 'S') stop_S = true;
          if (e.first == 'H') stop_H = true;
          if (e.first == 'D') stop_D = true;
          if (e.first == 'C') stop_C = true;
        }
      }
      if (child == 'J') {
        ans += 1;
        no_trump += 1;
        if (e.second.size() == 1 or e.second.size() == 2 or e.second.size() == 3) {
          ans--;
          no_trump--;
        }
      }
    }
  }
  if (ans < 14) return "PASS";
  if (stop_S and stop_H and stop_D and stop_C and no_trump >= 16) return "BID NO-TRUMP";
  if (ans >= 14) return findMax(sizes);
}

int main(void) {
  string line;
  unordered_map<char,vector<char>> m;
  while (getline(cin, line)) {
    m = split(line);
    // print(m);
    cout << getAns(m) << endl;
    m.clear();
  }
  return 0;
}
