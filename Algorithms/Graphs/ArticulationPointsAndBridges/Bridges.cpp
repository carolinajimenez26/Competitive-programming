// See https://codeforces.com/blog/entry/71146
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Node {
  int id, low, disc_time;
  bool visited;
  vector<Node*> neighbors;
  Node(int _id): id(_id), low(INF), disc_time(INF), visited(false) {}
};

struct Edge {
  Node *from, *to;

  void Print() {
    cout << from->id << " -> " << to->id << endl;
  }
};

void DFS(Node* curr, Node* parent, int time, vector<Edge>& ans) {
  curr->visited = true;
  curr->low = curr->disc_time = ++time;
  for (auto neigh : curr->neighbors) {
    if (neigh == parent) continue; // we don't want to go back through the same path.
                                  // if we go back is because we found another way back
    if (!neigh->visited) { // if neigh has not been discovered before
      DFS(neigh, curr, time, ans); // recursive DFS call
      if (curr->disc_time < neigh->low) {
        ans.push_back({curr, neigh});
      }
      curr->low = min(curr->low, neigh->low); // neigh->low might be an ancestor of u
    } else {// if neigh was already visited means that we found an ancestor
      curr->low = min(curr->low, neigh->disc_time); // finds the ancestor with the least discovery time
    }
  }
}

vector<Edge> FindBrigges(vector<Node*>& graph) {
  int time = 0;
  vector<Edge> ans;
  for (auto node : graph) {
    if (!node->visited) {
      DFS(node, node, time, ans);
    }
  }
  return ans;
}

int main(void) {
  int nodes = 5;
  vector<Node*> graph;
  for (int i = 0; i < nodes; i++) {
    graph.push_back(new Node(i));
  }
  graph[0]->neighbors = {graph[1]};
  graph[1]->neighbors = {graph[0], graph[2], graph[4]};
  graph[2]->neighbors = {graph[1], graph[3]};
  graph[3]->neighbors = {graph[2], graph[4]};
  graph[4]->neighbors = {graph[3], graph[1]};

  vector<Edge> bridges = FindBrigges(graph);
  cout << "Bridges: ";
  for (auto bridge : bridges) {
    bridge.Print();
  } // should print 0 -> 1

  return 0;
}