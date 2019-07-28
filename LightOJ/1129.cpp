#include <bits/stdc++.h>
using namespace std;

struct Node {
  map<char, Node*> edges;
  int frecuency;
  bool final_node;
  Node () : frecuency(0), edges(), final_node(false) {};
};

void Add(Node* node, string &s, int id) {
  node->frecuency++;
  if (id == s.size()) {
    node->final_node = true;
    return;
  }
  if (node->edges.count(s[id]) == 0) node->edges[s[id]] = new Node();
  Add(node->edges[s[id]], s, id + 1);
}

bool isConsistent(Node* node) {
  if ((node->final_node) && (node->frecuency > 1)) return false;
  for (map<char, Node*>::iterator it = node->edges.begin(); it != node->edges.end(); it++) {
    Node* next = it->second;
    if (!isConsistent(next)) return false;
  }
  return true;
}

void FreeTree(Node* node) {
  if (node == NULL) return;
  for (map<char, Node*>::iterator it = node->edges.begin(); it != node->edges.end(); it++) {
     FreeTree(it->second);
  }
  delete node;
}

int main(void) {
  int t, n, case_counter = 1;
  string phone_number;
  cin >> t;
  while (t--) {
    cin >> n;
    Node* root = new Node();
    for (int i = 0; i < n; i++) {
      cin >> phone_number;
      Add(root, phone_number, 0);
    }
    printf("Case %d: ", case_counter);
    if (isConsistent(root)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
    case_counter++;
    FreeTree(root);
  }
  return 0;
}
