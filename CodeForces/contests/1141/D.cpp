#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

void print(vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

struct word {
  string ori;
  string sorted;
  int size;
  bool isLeft;
  unordered_map<char, vector<int>> ori_pos;
  word(string s, bool _isLeft) {
    ori = s;
    size = s.size();
    isLeft = _isLeft;
    sort(s.begin(), s.end());
    sorted = s;
    saveOriPos();
  }

  void saveOriPos() {
    for (int i = 0; i < ori.size(); i++) {
      ori_pos[ori[i]].push_back(i);
    }
  }

  bool canBeUsed(char c) {
    return ori_pos.count(c) && ori_pos[c].size() > 0;
  }
};

void print(const vector<pair<int,int>>& s) {
  cout << s.size() << endl;
  for (auto p : s) {
    cout << p.first + 1 << " " << p.second + 1 << endl;
  }
}

void matchRepeted(word& l, word& r, vector<pair<int,int>>& result) {
  int j = r.size - 1;
  for (int i = l.size - 1; i >= 0 && j >= 0;) {
    if (l.sorted[i] == '?' || r.sorted[j] == '?') return;
    if (l.sorted[i] == r.sorted[j]) {
      int x = l.ori_pos[l.sorted[i]].back();
      int y = r.ori_pos[r.sorted[j]].back();
      result.push_back(make_pair(x,y));
      l.ori_pos[l.sorted[i]].pop_back();
      r.ori_pos[r.sorted[j]].pop_back();
      i--;
      j--;
      continue;
    }
    if (l.sorted[i] < r.sorted[j]) j--;
    else i--;
  }
}

int matchRest(vector<int>& qm, word& w, vector<pair<int,int>>& result) {
  int i = w.size - 1, x, y;
  int qm_to_remove = 0;
  while (qm.size() && i >= 0) {
    char curr_char = w.sorted[i];
    if (curr_char == '?') return qm_to_remove;
    if (w.canBeUsed(curr_char)) {
      x = w.ori_pos[curr_char].back();
      y = qm.back();
      qm_to_remove++;
      w.ori_pos[curr_char].pop_back();
      qm.pop_back();
      if (!w.isLeft) result.push_back(make_pair(y,x));
      else result.push_back(make_pair(x,y));
    }
    i--;
  }
  return qm_to_remove;
}

void matchQM(word& l, word& r, vector<pair<int,int>>& result) {
  vector<int> qm_l, qm_r;
  if (l.canBeUsed('?')) qm_l = l.ori_pos['?'];
  if (r.canBeUsed('?')) qm_r = r.ori_pos['?'];

  while (qm_l.size() && qm_r.size()) {
    result.push_back(make_pair(qm_l.back(), qm_r.back()));
    qm_l.pop_back();
    qm_r.pop_back();
  }
}

void removeQM(word& w, int& qm_to_remove) {
  for (int i = 0; i < qm_to_remove; i++) {
    w.ori_pos['?'].pop_back();
  }
}

vector<pair<int,int>> coloredBoots(word& l, word& r) {
  vector<pair<int,int>> result;

  matchRepeted(l, r, result);

  vector<int> qm_l, qm_r;
  if (l.canBeUsed('?')) qm_l = l.ori_pos['?'];
  if (r.canBeUsed('?')) qm_r = r.ori_pos['?'];
  int qm_to_remove;
  qm_to_remove = matchRest(qm_l, r, result);
  removeQM(l, qm_to_remove);
  qm_to_remove = matchRest(qm_r, l, result);
  removeQM(r, qm_to_remove);

  matchQM(l, r, result);

  return result;
}

int main(void) {
  int n;
  char c;
  string left = "", right = "";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c;
    left.push_back(c);
  }
  word l(left, true);
  for (int i = 0; i < n; i++) {
    cin >> c;
    right.push_back(c);
  }
  word r(right, false);
  vector<pair<int,int>> result = coloredBoots(l, r);
  print(result);
}
