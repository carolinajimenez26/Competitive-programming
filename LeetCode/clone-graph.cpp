#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
private:
  unordered_map<int, Node*> visited;

  Node* Clone(Node* node) {
    if (node == nullptr) {
      return node;
    }
    Node* copy = new Node(node->val);
    visited[node->val] = copy;
    for (auto neigh : node->neighbors) {
      Node* neigh_copy = nullptr;
      if (visited.count(neigh->val) > 0) {
        neigh_copy = visited[neigh->val];
      } else {
        neigh_copy = cloneGraph(neigh);
      }
      copy->neighbors.push_back(neigh_copy);
    }
    return copy;
  }
public:
  Node* cloneGraph(Node* node) {
    return Clone(node);
  }
};

int main(void) {
  Node* one = new Node(1);
  Node* two = new Node(2);
  Node* three = new Node(3);
  Node* four = new Node(4);

  one->neighbors.push_back(two);
  two->neighbors.push_back(one);

  two->neighbors.push_back(three);
  three->neighbors.push_back(two);

  four->neighbors.push_back(one);
  one->neighbors.push_back(four);

  Solution sol;
  sol.cloneGraph(one);
  return 0;
}