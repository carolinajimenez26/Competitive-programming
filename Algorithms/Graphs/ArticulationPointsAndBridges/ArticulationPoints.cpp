// See https://codeforces.com/blog/entry/71146
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Node {
  int id, low, disc_time;
  bool visited, is_articulation_point;
  vector<Node*> neighbors;
  Node(int _id): id(_id), low(INF), disc_time(INF), visited(false), is_articulation_point(false) {}
};

int DFS(Node* curr, Node* parent, int time) {
  curr->visited = true;
  int children = 0;
  curr->low = curr->disc_time = ++time;
  for (auto neigh : curr->neighbors) {
    if (neigh == parent) continue; // we don't want to go back through the same path.
                                  // if we go back is because we found another way back
    if (!neigh->visited) { // if neigh has not been discovered before
      children++;
      DFS(neigh, curr, time); // recursive DFS call
      if (curr->disc_time <= neigh->low) // condition #1
        curr->is_articulation_point = true;
      curr->low = min(curr->low, neigh->low); // neigh->low might be an ancestor of u
    } else {// if neigh was already visited means that we found an ancestor
      curr->low = min(curr->low, neigh->disc_time); // finds the ancestor with the least discovery time
    }
  }
  return children;
}

void FindArticulationPoints(vector<Node*>& graph) {
  int time = 0;
  for (auto node : graph) {
    if (!node->visited) {
      int children = DFS(node, node, time);
      node->is_articulation_point = children >= 2; // condition #2
    }
  }
}

int main(void) {
  int nodes = 4;
  vector<Node*> graph;
  for (int i = 0; i < nodes; i++) {
    graph.push_back(new Node(i));
  }
  graph[0]->neighbors = {graph[1], graph[3]};
  graph[1]->neighbors = {graph[0], graph[2], graph[3]};
  graph[2]->neighbors = {graph[1]};
  graph[3]->neighbors = {graph[1], graph[0]};
  // until here the articulation point is only node 1

  graph.push_back(new Node(4));
  graph[4]->neighbors = {graph[0]};
  graph[0]->neighbors.push_back(graph[4]);
  // until here the articulation points are 0 and 1

  FindArticulationPoints(graph);
  cout << "Articulation points: ";
  for (auto node : graph) {
    if (node->is_articulation_point) cout << node->id << " ";
  }
  cout << endl;

  return 0;
}