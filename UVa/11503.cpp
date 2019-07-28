#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class UnionFind {
  private:
    vector<int> p, rank, size;
  public:
    UnionFind(int N) {
      rank.assign(N, 0);
      p.assign(N, 0);
      size.assign(N, 1);
      for (int i = 0; i < N; i++) p[i] = i;
    }

    UnionFind() {}

    void add(int i) {
      p.push_back(i);
      rank.push_back(0);
      size.push_back(1);
    }

    int findSet(int i) {
      return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    int getSize(int i) {
      return size[i];
    }

    void printSize() {
      dbg("printSize");
      for (int i = 0; i < size.size(); i++) {
        cout << size[i] << " ";
      }
      cout << endl;
    }

    void print(map<int, string> decode) {
      for (int i = 0; i < p.size(); i++)
        cout << decode[i] << ": dad is " << decode[p[i]] << endl;
    }

    void unionSet(int i, int j) {
      if (!isSameSet(i,j)) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
          p[y] = x; // rank keeps the tree short
          size[x] += size[y];
        }
        else {
          p[x] = y;
          size[y] += size[x];
          if (rank[x] == rank[y]) rank[y]++;
        }
      }
    }
};

void add(string s, map<string, int> &code, map<int, string> &decode, int id) {
  decode[id] = s;
  code[s] = id;
}

int main(void) {
  long int tc, F;
  string s1, s2;
  cin >> tc;
  map<string, int> code;
  map<int, string> decode;
  while (tc--) {
    code.clear();
    decode.clear();
    cin >> F;
    UnionFind uf;
    for (int i = 0; i < F; i++) {
      cin >> s1 >> s2;
      if (!code.count(s1)) {
        uf.add(code.size());
        add(s1, code, decode, code.size());
      }
      if (!code.count(s2)) {
        uf.add(code.size());
        add(s2, code, decode, code.size());
      }
      uf.unionSet(code[s1], code[s2]);
      cout << uf.getSize(uf.findSet(code[s1])) << endl;
      // uf.print(decode);
      // uf.printSize();
    }
  }
  return 0;
}
