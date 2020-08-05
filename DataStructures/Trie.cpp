#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

struct Node {
  unordered_map<char, Node*> edges;
  int freq;
  bool final_node;
  Node () : freq(0), edges(), final_node(false) {};
};

class Trie {
private:
  Node* root;

  // Op 1
  // Node* Add(Node* node, string &s, int id) {
  //   if (node == nullptr) node = new Node();
  //   if (id == s.size()) return node;
  //   Node* next = node->edges.count(s[id]) ? node->edges[s[id]] : nullptr;
  //   next = Add(next, s, id + 1);
  //   node->edges[s[id]] = next; // Add it to the tree
  //   return node;
  // }

  // Op 2
  void Add(Node* node, const string &s, int id) {
    node->freq++;
    if (id == s.size()) {
      node->final_node = true;
      return;
    }
    if (node->edges.count(s[id]) == 0) node->edges[s[id]] = new Node();
    Add(node->edges[s[id]], s, id + 1);
  }

  bool Find(Node* node, const string &s, int id) {
    if (id == s.size()) { // the word was consumed
      return node->final_node;
    }
    if (node->edges.count(s[id]) == 0) return false;
    return Find(node->edges[s[id]], s, id + 1);
  }

public:
  Trie() {
    root = new Node();
  }

  void Add(const string &s) {
    Add(root, s, 0);
  }

  bool Find(const string& s) {
    return Find(root, s, 0);
  }
};

int main(void) {
  Trie trie;
  string toby = "Toby", tomy = "Tomy";
  trie.Add(toby);
  trie.Add(tomy);
  assert(trie.Find(toby)); // true
  assert(trie.Find(tomy)); // true 
  assert(!trie.Find("other")); // false
  return 0;
}
