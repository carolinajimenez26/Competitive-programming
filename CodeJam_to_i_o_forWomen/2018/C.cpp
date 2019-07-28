#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string ori;

void print(set<char> s) {
  set<char>::iterator it;
  for(it = s.begin(); it != s.end(); ++it) cout << *it;
  cout << endl;
}

void print(vector<string> &v) {
  for (auto& e : v) {
    cout << e << " ";
  }
  cout << endl;
}

void print(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << endl;
}

string convert(set<char> s) {
  set<char>::iterator it;
  string ans = "";
  for(it = s.begin(); it != s.end(); ++it) {
    ans.push_back(*it);
  }
  return ans;
}

int get_id(char a) {  // CAXTB
  for (int i = 0; i < ori.size(); i++) {
    if (a == ori[i])
      return i;
  }
  assert(false);
  return -1;
}

// a = abc
// b = bbb
// ori = bca
bool comp(const string &a, const string &b) {
  int len = min(a.size(), b.size());
  int i = 0;
  for (; i < len; i++) {
    if (a[i] != b[i]) {
      int x = get_id(a[i]);
      int y = get_id(b[i]);
      return x < y;
    }
  }
  return false;
}

void middle(vector<int> &middles, vector<string> &aux, vector<string> original) {
  string pivot;
  if (aux.size() % 2 == 0) { // there are 2 middles

  } else { // there is 1 middle
    pivot = aux[aux.size() / 2];
    for (int i = 0; i < original.size(); i++) {
      if (original[i] == pivot) {
        middles[i] = 1;
        break;
      }
    }
  }
}

void solver(vector<int> &middles, string &order, vector<string> &aux,
            vector<string> &original, int t_case) {
  vector<string> tmp;
  do {
    ori = order;
    sort(aux.begin(), aux.end(), comp);
    middle(middles, aux, original);
  } while ( next_permutation(order.begin(), order.end()) );

  cout << "Case #" << t_case << ": ";
  for (int i = 0; i < middles.size(); i++) {
    cout << (middles[i] ? "YES" : "NO");
    if (i != middles.size() - 1) cout << " ";
  }
  cout << endl;
}

int tonum(string &s) {
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

vector<string> split(string &s) {
  stringstream ss;
  ss << s;
  vector<string> v;
  string tok;
  while (ss >> tok)
    v.push_back(tok);
  return v;
}

int main(void) {
  int t, l, count = 1;
  string s, s_tmp;
  getline(cin, s_tmp);
  t = tonum(s_tmp);
  s_tmp.clear();
  vector<string> v;
  vector<int> middles;
  while (t--) {
    set<char> orders;
    getline(cin, s_tmp);
    l = tonum(s_tmp);
    middles.clear();

    getline(cin, s_tmp);
    v = split(s_tmp);
    vector<string> v_original(v.begin(), v.end());
    middles.resize(v.size());

    for(auto& e : v) {
      for (auto& c : e) orders.insert(c);
    }

    // print(orders);
    // print(v);
    // print(middles);
    string tmp = convert(orders);
    solver(middles, tmp, v, v_original, count);
    count++;
  }
  return 0;
}
