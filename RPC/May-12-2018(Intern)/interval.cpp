#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void insert(int x, map<int, int> &m) {
  if (m.count(x) == 0) { // if doesn't exists yet
    m[x] = 1;
  } else {
    m[x] += 1;
  }
}

void _delete(int x, map<int, int> &m) {
  if (m.count(x) != 0) { // if doesn't exists
    if (m[x] == 1) { // remove it all
      m.erase(x);
    } else { // decrease frecuency
      m[x] -= 1;
    }
  }
}

void query(int y, map<int, int> &m) {
  int x = -1; // max of m that is less than y
  int z = 100001; // min of m that is greater than y
  map<int, int>::iterator it, it1, it2;
  it = m.find(y);

  if (it == m.end()) { // the element doesn't exists in m
    it2 = m.upper_bound(y);
    it1 = it2;
    if (it1 != m.begin()) --it1;
    if (it1->first < y) x = it1->first;
    if (it2->first > y) z = it2->first;
  } else {
    it1 = it2 = it;
    ++it2;
    if (it1 != m.begin()) { // there is a number less than y in m
      // cout << "entra" << endl;
      --it1;
      x = it1->first;
    } // else cout << "begin " << it1->first << endl;
    if (it2 != m.end()) {
      z = it2->first;
    }
  }
  cout << x << " " << z << endl;
}

void print(map<int, int> m) {
  for (auto it : m) {
    cout << it.first << " -> " << it.second << endl;
  }
  cout << endl;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, x, q, p, y;
  map<int, int> m; // number, frecuency
  cin >> t;
  while (t--) {
    m.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      insert(x, m);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
      cin >> p >> y;
      if (p == 1) {
        query(y, m);
      }
      if (p == 2) {
        insert(y, m);
      }
      if (p == 3) {
        _delete(y, m);
      }
      // print(m);
    }
  }
  return 0;
}
