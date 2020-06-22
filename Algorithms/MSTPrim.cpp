#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

struct Edge {
  int id, to, weight;
  bool used;

  Edge(int _id, int _to, int _weight) : id(_id), to(_to), weight(_weight), used(false) {}

  bool operator<(const Edge& other) const {
    return weight > other.weight; // priority queues orders from greater to smaller,
                                  // so we use > to get the opposite result here
                                  // the one with higher weight has less priority
  }

  bool operator==(const Edge& other) const {
    return id == other.id;
  }

  void Print() {
    cout << "(" << id + 1 << ")" << to + 1 << ", w: " << weight; // 1 index because of the input
  }
};

struct Node {
  int val;
  bool used;
  vector<Edge> neighbors;

  Node(int _val) : val(_val), used(false) {}

  void Print() {
    cout << val + 1 << "(" << used << ")" << " -> "; // 1 index because of the input
    for (auto neigh : neighbors) {
      cout << "[ ";
      neigh.Print();
      cout << "], ";
    }
  }
};

void Process(priority_queue<Edge>& pq, Node* node, vector<Node*>& nodes) {
  node->used = true;
  for (auto edge : node->neighbors) {
    Node *neigh = nodes[edge.to];
    if (!neigh->used) {
      pq.push(edge);
    }
  }
}

vector<Edge> FindMST(vector<Node*>& nodes) {
  if (nodes.empty()) return {};
  vector<Edge> ans;
  priority_queue<Edge> pq;
  Process(pq, nodes[0], nodes);
  while (!pq.empty()) {
    Edge edge = pq.top();
    pq.pop();
    Node *node = nodes[edge.to];
    if (!node->used) {
      ans.push_back(edge);
      Process(pq, node, nodes);
    }
  }
  return ans;
}

void Print(const vector<Node*>& nodes) {
  cout << "----------------" << endl;
  for (auto node : nodes) {
    node->Print();
    cout << endl;
  }
  cout << "----------------" << endl;
}

void Print(const vector<Edge>& edges) {
  cout << "*****************" << endl;
  for (auto edge : edges) {
    edge.Print();
    cout << endl;
  }
  cout << "*****************" << endl;
}

int main(void) {
  /*
    Receive number of nodes and number of connections, like this:
    4 5
    1 2 101
    1 3 100
    2 3 2
    2 4 2
    3 4 1
  */
  int n, m;
  cin >> n >> m;
  vector<Node*> nodes(n);
  for (int i = 0; i < n; i++) {
    nodes[i] = new Node(i);
  }
  for (int i = 0; i < m; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    from--; to--;
    nodes[from]->neighbors.push_back({i, to, weight});
    nodes[to]->neighbors.push_back({i, from, weight});
  }
  Print(nodes);
  vector<Edge> MST = FindMST(nodes);
  Print(MST);
  return 0;
}