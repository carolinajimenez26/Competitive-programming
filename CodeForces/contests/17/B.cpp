#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct Node {
  int idx, q;
  Node(int _idx, int _q) : idx(_idx), q(_q) {}

  bool operator<(const Node& other) const {
    return idx < other.idx;
  }

  void Print() {
    cout << "(" << (idx + 1) << ")" << q << endl;
  }
};

struct Edge {
  Node *from, *to;
  int weight;

  bool operator<(const Edge& other) const {
    if(weight != other.weight) return weight < other.weight;
    if (from->idx != other.from->idx) return from->idx < other.from->idx;
    return to->idx < other.to->idx;
  }

  void Print() {
    cout << (from->idx + 1) << "->" << (to->idx + 1) << ": " << weight << endl;
  }
};

class DisjointSet {
private:
  unordered_map<Node*, Node*> parent; // child -> parent

public:
  void MakeSet(const vector<Node*>& graph) {
    for (auto node : graph) {
      parent[node] = node;
    }
  }

  Node* FindSet(Node* n) {
    if (parent[n] == n) return n;
    return (parent[n] = FindSet(parent[n]));
  }

  void UnionSet(Node* a, Node* b) {
    parent[a] = b;
  }

  void Print() {
    for (auto [p, c] : parent) {
      cout << p->idx << "->" << c->idx << endl;
    }
    cout << endl;
  }
};

int GetHierarchyMinCost(const vector<Node*>& graph, const set<Edge>& edges) {
  DisjointSet ds;
  ds.MakeSet(graph);
  int ans = 0;
  set<Node*> has_supervisor;
  for (auto edge : edges) {
    if (ds.FindSet(edge.from) != ds.FindSet(edge.to) && has_supervisor.count(edge.to) == 0) {
      ds.UnionSet(edge.from, edge.to);
      ans += edge.weight;
      has_supervisor.insert(edge.to);
    }
  }
  return has_supervisor.size() == graph.size() - 1 ? ans : -1;
}

void Print(const set<Edge>& edges) {
  for (auto edge : edges) {
    edge.Print();
  }
  cout << endl;
}

void Print(const vector<Node*>& graph) {
  for (auto node : graph) {
    node->Print();
  }
  cout << endl;
}

int main(void) {
  bool possible = true;
  int n;
  cin >> n;
  vector<Node*> graph(n);
  for (int i = 0; i < n; i++) {
    int q;
    cin >> q;
    Node *node = new Node(i, q);
    graph[i] = node;
  }
  // Print(graph);
  int m;
  cin >> m;
  set<Edge> edges;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    Edge e{graph[a], graph[b], c};
    edges.insert(e);
  }
  // Print(edges);
  int ans = GetHierarchyMinCost(graph, edges);
  cout << ans << endl;
  return 0;
}