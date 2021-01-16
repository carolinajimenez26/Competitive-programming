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
};

struct Cost {
  Node* node;
  int cost;

  Cost(Node* node, int cost): node(node), cost(cost) {}

  bool operator<(const Cost& other) const {
    // Return min cost as "high priority".
    return cost > other.cost;
  }
};

struct Node {
  int id;
  vector<Edge> edges;

  Node(int id): id(id) {}
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
  priority_queue<Cost> q;
  distances[source->id] = 0;
  q.emplace(source, 0);
  while (!q.empty()) {
    Cost curr_cost = q.top();
    q.pop();
    Node* curr = curr_cost.node;
    if (curr_cost.cost > distances[curr->id]) {
      // Old cost, ignore.
      continue;
    }

    for (auto edge : curr->edges) {
      Node* to = edge.node;
      if (distances[to->id] > distances[curr->id] + edge.weight) {
        // set.erase(Cost(to, distances[to->id]))
        distances[to->id] = distances[curr->id] + edge.weight;
        // set.insert(Cost(to, distances[to->id]))
        q.emplace(to, distances[to->id]);
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