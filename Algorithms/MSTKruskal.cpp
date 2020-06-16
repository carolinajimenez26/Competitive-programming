#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

class DisjointSet {
private:
  vector<int> parent;
public:
  DisjointSet(int size) {
    parent.resize(size);
  }

  void MakeSet() {
    for (int i = 0; i < parent.size(); i++) {
      parent[i] = i;
    }
  }

  int FindSet(int node) {
    if (node == parent[node]) return node;
    return parent[node] = FindSet(parent[node]);
  }

  void UnionSet(int a, int b) {
    a = FindSet(a);
    b = FindSet(b);
    if (a != b) {
      parent[b] = a;
    }
  }

  void Print() {
    for (int i = 0; i < parent.size(); i++) {
      cout << "parent of " << i << " is " << parent[i] << endl;
    }
  }
};


struct Edge {
  int u, v, weight;
  bool operator<(Edge const& other) const {
    return weight < other.weight;
  }
  void Print() {
    cout << u << "->" << v << ": " << weight << endl;
  }
};

void Print(const vector<Edge>& v) {
  for (auto e : v) {
    e.Print();
  }
  cout << endl;
}

vector<Edge> GetMST(vector<Edge>& edges, int nodes) {
  vector<Edge> result;
  sort(edges.begin(), edges.end());
  DisjointSet ds(nodes);
  ds.MakeSet();

  for (auto edge : edges) {
    if (ds.FindSet(edge.u) != ds.FindSet(edge.v)) {
      ds.UnionSet(edge.u, edge.v);
      result.push_back(edge);
    }
  }
  return result;
}

int main(void) {
  /*
    - Here we should receive all the edges in the form:
      u v c
      Meaning we have an edge from u to v with cost c
    - At the same time, we should count how many different nodes there are in the
      graph, using for example a set, and every time adding u and v to the set.

    Example input:
      9
      4 3 9
      4 0 4
      3 2 5
      2 5 8
      0 1 2
      1 5 7
      0 3 1
      3 1 3
      1 2 3
  */
  int lines; // input
  cin >> lines;
  set<int> nodes;
  vector<Edge> edges;
  for (int i = 0; i < lines; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    nodes.insert(u);
    nodes.insert(v);
    Edge e1{u,v,c};
    edges.push_back(e1);
    Edge e2{v, u,c};
    edges.push_back(e2);
  }
  dbg(nodes.size());
  Print(edges);
  vector<Edge> mst = GetMST(edges, nodes.size());
  cout << "MST:" << endl;
  Print(mst);
  return 0;
}