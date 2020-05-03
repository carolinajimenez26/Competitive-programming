#include <iostream>
#include <vector>
using namespace std;

struct Cell {
  int row, col;
};

class Node {
private:
  Cell cell;
  vector<Node*> neighbors;
  bool visited;
public:
  Node(Cell _cell): cell(_cell), visited(false) {}

  void AddNeighbor(Node* n) {
    neighbors.push_back(n);
  }

  bool IsNeighborOf(const Node* n) {
    return cell.row == n->cell.row || cell.col == n->cell.col;
  }

  void Visit() {
    visited = true;
  }

  bool IsVisited() {
    return visited;
  }

  vector<Node*> GetNeighbors() {
    return neighbors;
  }
};

vector<Node*> ContructGraph(const vector<Cell>& v) {
  vector<Node*> graph;
  for (auto cell : v) {
    Node* n = new Node(cell);
    graph.push_back(n);
  }
  for (int i = 0; i < graph.size(); i++) {
    for (int j = i + 1; j < graph.size(); j++) {
      if (graph[i]->IsNeighborOf(graph[j])) {
        graph[i]->AddNeighbor(graph[j]);
        graph[j]->AddNeighbor(graph[i]);
      }
    }
  }
  return graph;
}

void DFS(Node* n, vector<Node*>& visited) {
  n->Visit();
  visited.push_back(n);
  for (auto neighbor : n->GetNeighbors()) {
    if (!neighbor->IsVisited()) {
      DFS(neighbor, visited);
    }
  }
}

vector<vector<Node*>> GetComponents(const vector<Node*>& graph) {
  vector<vector<Node*>> components;
  for (auto node : graph) {
    vector<Node*> component;
    DFS(node, component);
    components.push_back(component);
  }
  return components;
}

class Solution {
public:
  int removeStones(vector<vector<int>>& stones) {
    vector<Cell> in;
    for (auto v : stones) {
      in.push_back({v[0],v[1]});
    }
    vector<Node*> graph = ContructGraph(in);
    vector<vector<Node*>> components = GetComponents(graph);
    int sum = 0;
    for (auto component : components) {
      sum += (component.size() - 1);
    }
    return sum;
  }
};

int main(void) {
  vector<vector<int>> in = {{0,0}, {0,1}, {1,0}, {1,2}, {2,1}, {2,2}};
  Solution sol;
  cout << sol.removeStones(in) << endl;
  return 0;
}