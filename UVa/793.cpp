#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class UnionFind {
  private:
    vector<int> p, rank;
  public:

    UnionFind() {}

    UnionFind(int N) {
      rank.assign(N, 0);
      p.assign(N, 0);
      for (int i = 0; i < N; i++) p[i] = i;
    }

    void print() {
      for (int i = 0; i < p.size(); i++) cout << i << ": dad is " << p[i] << endl;
    }

    void resize(int N) {
      rank.assign(N, 0);
      p.assign(N, 0);
      for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet(int i) {
      return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
      if (!isSameSet(i,j)) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
        else {
          p[x] = y;
          if (rank[x] == rank[y]) rank[y]++;
        }
      }
    }
};

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
  int tc, edges, x, y, afirmative, negative, n1, n2, original_tc;
  string s;
  char c;
  getline(cin, s);
  tc = tonum(s);
  original_tc = tc;
  s.clear();
  bool flag;
  UnionFind uf;
  while (true) {
    if (tc == -1) break;
    s.clear();
    getline(cin, s);
    if (s == "") {
      flag = true;
      if (tc != original_tc) cout << afirmative << "," << negative << endl;
      if (tc != original_tc and tc != 0) cout << endl;
      afirmative = negative = 0;
      tc--;
    } else {
      if (flag) {
        edges = tonum(s);
        flag = false;
        uf.resize(edges);
      }
      else {
        vector<string> v = split(s);
        n1 = tonum(v[1]) - 1, n2 = tonum(v[2]) - 1;
        if (v[0] == "c") {
          uf.unionSet(n1, n2);
          // uf.print();
        } else {
          uf.isSameSet(n1, n2) ? afirmative++ : negative++;
        }
      }
    }
  }
  return 0;
}
