#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class UnionFind {
  private:
    vector<int> p, rank;
  public:
    int sets;

    UnionFind(int N) {
      rank.assign(N, 0);
      sets = N;
      p.assign(N, 0);
      for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet(int i) {
      return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    void print(map<int, char> decode) {
      for (int i = 0; i < p.size(); i++)
        cout << decode[i] << ": dad is " << decode[p[i]] << endl;
        // cout << i << ": dad is " << p[i] << endl;
    }

    void unionSet(int i, int j) {
      if (!isSameSet(i,j)) {
        sets--;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
        else {
          p[x] = y;
          if (rank[x] == rank[y]) rank[y]++;
        }
      }
    }
};

void print(map<char, int> m) {
  for (auto &e : m) {
    cout << e.first << "->" << e.second << endl;
  }
}

void print(set<char> st) {
  cout << "print set" << endl;
  for (set<char>::iterator it = st.begin(); it != st.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

void print(map<char, vector<char> > graph) {
  for (auto& e : graph) {
    cout << e.first << " -> ";
    for (auto& n : e.second) cout << n << " ";
    cout << endl;
  }
}

void solver(UnionFind uf, map<char, vector<char> > graph, map<char, int> code,
            map<int, char> decode, string wake_up_areas) {
  int pivote = code[wake_up_areas[0]];
  int years = 0;
  vector<int> v;

  while (true) {
    v.clear();
    for (auto& e : graph) {
      if (!uf.isSameSet(pivote, code[e.first])) {
        int neighs_awake = 0;
        for (auto& neigh : e.second) { // find if can wake up
          if (uf.isSameSet(pivote, code[neigh])) neighs_awake++;
          if (neighs_awake == 3) {
            v.push_back(code[e.first]);
            break;
          }
        }
      }
    }
    if (v.size() == 0) break;
    // add the new awake areas to the set
    for (auto& i : v) uf.unionSet(pivote, i);
    years++;
  }

  if (uf.sets != 1) cout << "THIS BRAIN NEVER WAKES UP" << endl;
  else cout << "WAKE UP IN, " << years << ", YEARS" << endl;

}

int main(void) {
  int slept_areas, connections;
  char c1, c2;
  string wake_up_areas;
  set<char> st, not_awake;
  map<char, vector<char> > graph;
  map<char, int> code; // e.g A -> 0
  map<int, char> decode; // e.g 0 -> A
  while (cin >> slept_areas) {
    graph.clear();
    code.clear();
    decode.clear();
    st.clear();
    not_awake.clear();
    cin >> connections;
    cin >> wake_up_areas;
    for (int i = 0; i < connections; i++) {
      cin >> c1 >> c2;
      st.insert(c1);
      st.insert(c2);
      not_awake.insert(c1);
      not_awake.insert(c2);
      graph[c1].push_back(c2);
      graph[c2].push_back(c1);
    }
    for (int i = 0; i < wake_up_areas.size(); i++) {
      st.insert(wake_up_areas[i]);
      not_awake.erase(wake_up_areas[i]);
    }
    int i = 0;
    for (set<char>::iterator it = st.begin(); it != st.end(); ++it, i++) {
      code[*it] = i;
      decode[i] = *it;
    }
    UnionFind uf(st.size());
    // uf.print(decode);
    for (int i = 0; i < wake_up_areas.size() - 1; i++) {
      uf.unionSet(code[wake_up_areas[i]], code[wake_up_areas[i + 1]]);
    }
    // uf.print(decode);
    // print(not_awake);
    // print(graph);
    if (slept_areas == 0) cout << "WAKE UP IN, " << 0 << ", YEARS" << endl;
    else {
      if (connections == 0) {
        if (wake_up_areas.size() < slept_areas)
        cout << "THIS BRAIN NEVER WAKES UP" << endl;
        else cout << "WAKE UP IN, " << 0 << ", YEARS" << endl;
      } else solver(uf, graph, code, decode, wake_up_areas);
    }
  }
  return 0;
}
