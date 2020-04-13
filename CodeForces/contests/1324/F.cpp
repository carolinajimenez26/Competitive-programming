#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
#define INF numeric_limits<int>::max()

using namespace std;

struct Node {
  int down;
  int best;
  int color; // -1 = black, 1 = white
  vector<Node*> children;
  Node(int _color): color(_color) {}
  Node(): Node(0) {}

  void AddNeigh(Node* n) {
    children.push_back(n);
  }
};

void Down(Node* node, Node* parent) {
  node->down = node->color;
  for (auto child : node->children) {
    if (child == parent) continue;
    Down(child, node);
    if (child->down > 0) {
      node->down += child->down;
    }
  }
}

void Best(Node* node, Node* parent) {
  if (node == parent) {
    Down(node, parent);
    node->best = node->down;
  }
  for (auto child : node->children) {
    if (child == parent) continue;
    if (child->down >= 0) {
      child->best = max(node->best, child->down);
    } else {
      child->best = max(child->down, node->best + child->color);
    }
    Best(child, node);
  }
}

int main(void) {
  int n;
  cin >> n;
  vector<Node*> graph(n);
  for (int i = 0; i < n; i++) {
    int color;
    cin >> color;
    color = color == 0 ? -1 : 1;
    graph[i] = new Node(color);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--; // 0 index
    graph[u]->AddNeigh(graph[v]);
    graph[v]->AddNeigh(graph[u]);
  }
  Best(graph[0], graph[0]);
  // print(graph);
  for (auto node : graph) {
    cout << node->best << " ";
  }
  cout << endl;
}