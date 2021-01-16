#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

struct Node;
struct Edge {
  Node* node;
  int weight;

  Edge(Node* node, int weight): node(node), weight(weight) {}

  bool operator<(const Edge& other) const {
    return weight > other.weight;
  }
};

struct Node {
  int val;
  vector<Edge> edges;

  Node(int val): val(val) {}
};

class Graph {
public:
  Graph(int nodes) {
    for (int i = 0; i < nodes; i++) {
      graph.push_back(new Node(i));
    }
  }

  void AddEdge(int from, int to, int weight) {
    graph[from]->edges.emplace_back(graph[to], weight);
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

  ~Graph() {
    for (int i = 0; i < graph.size(); i++) {
      delete graph[i];
    }
  }
private:
  vector<Node*> graph;
};

vector<int> Dijkstra(const Graph& graph, Node* source) {
  const int INF = numeric_limits<int>::max();
  vector<int> distances(graph.GetSize(), INF);
  priority_queue<Edge> q;
  distances[source->val] = 0;
  q.emplace(source, 0);
  while (!q.empty()) {
    Edge curr_edge = q.top();
    q.pop();
    Node* curr = curr_edge.node;
    int curr_weight = curr_edge.weight;
    for (auto edge : curr->edges) {
      Node* to = edge.node;
      if (distances[to->val] > distances[curr->val] + edge.weight) {
        distances[to->val] = distances[curr->val] + edge.weight;
        q.push(edge);
      }
    }
  }
  return distances;
}

void PrintDistances(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << i + 1 << "->" << v[i] << endl;
  }
}

int main(void) {
  int nodes, edges, u, v, w;
  cin >> nodes >> edges;
  Graph graph(nodes);

  for (int i = 0; i < edges; i++) {
    cin >> u >> v >> w;
    u--; v--;
    graph.AddEdge(u, v, w);
  }

  assert("Graph should have at least one node" && graph.GetSize() != 0);
  vector<int> distances = Dijkstra(graph, graph.GetNode(0));
  PrintDistances(distances);
  return 0;
}