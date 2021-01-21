#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node {
  int id;
  vector<Node*> neighs;
  bool visited;

  Node(int id): id(id), visited(false) {}

  bool operator==(const Node& other) const {
    return id == other.id;
  }
};

class Graph {
public:
  Graph(int nodes) {
    for (int i = 0; i < nodes; i++) {
      graph.push_back(new Node(i));
    }
  }

  void AddEdge(int from, int to) {
    graph[from]->neighs.emplace_back(graph[to]);
  }

  int GetSize() const {
    return graph.size();
  }

  bool IsValid(int idx) {
    return idx >= 0 && idx < graph.size();
  }

  Node* GetNode(int idx) {
    assert(IsValid(idx));
    return graph[idx];
  }

  vector<int> FindSmallestSetOfVertices() {
    set<int> ans;
    for (auto node : graph) {
      if (!node->visited) {
        ans.insert(node->id);
        DFS(node, node, ans);
      }
    }
    return vector<int>(ans.begin(), ans.end());
  }

  ~Graph() {
    for (int i = 0; i < graph.size(); i++) {
      delete graph[i];
    }
  }
private:
  vector<Node*> graph;

  void DFS(Node* curr, Node* parent, set<int>& sources) {
    curr->visited = true;
    for (auto neigh : curr->neighs) {
      if (neigh == parent) {
        continue;
      }
      if (neigh->visited) {
        sources.erase(neigh->id);
        continue;
      }
      DFS(neigh, curr, sources);
    }
  }
};

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    Graph graph(n);
    for (auto edge : edges) {
      int from = edge[0];
      int to = edge[1];
      graph.AddEdge(from, to);
    }
    return graph.FindSmallestSetOfVertices();
  }
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl; 
}

int main(void) {
  Solution sol;
  vector<vector<int>> edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};
  int n = 6;
  vector<int> out = sol.findSmallestSetOfVertices(n, edges);
  Print(out);
  return 0;
}