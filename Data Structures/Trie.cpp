#include <bits/stdc++.h>
using namespace std;

struct Node {
  map<char, Node*> edges;
  int frecuency;
  bool final_node;
  Node () : frecuency(0), edges(), final_node(false) {};
};

// Op 1
// Node* Add(Node* node, string &s, int id) {
//   if (node == nullptr) node = new Node();
//   if (id == s.size()) return node;
//   Node* next = node->edges.count(s[id]) ? node->edges[s[id]] : nullptr;
//   next = Add(next, s, id + 1);
//   node->edges[s[id]] = next; // Add it to the tree
//   return node;
// }

void Add(Node* node, string &s, int id) {
  node->frecuency++;
  if (id == s.size()) {
    node->final_node = true;
    return;
  }
  if (node->edges.count(s[id]) == 0) node->edges[s[id]] = new Node();
  Add(node->edges[s[id]], s, id + 1);
}

int main(void) {
  Node* root = new Node();
  string toby = "Toby", tomy = "Tomy";
  Add(root, toby, 0);
  Add(root, tomy, 0);
  return 0;
}
