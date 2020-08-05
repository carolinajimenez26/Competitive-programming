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
    if (s[id] == '.') {
      for (auto [letter, next_node] : node->edges) {
        if (Find(next_node, s, id + 1)) return true;
      }
      return false;
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

class WordDictionary {
private:
  Trie trie;

public:
  WordDictionary() {}
  
  void addWord(string word) {
    trie.Add(word);
  }
  
  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return trie.Find(word);
  }
};

int main(void) {
  WordDictionary* wd = new WordDictionary();
  wd->addWord("bad");
  wd->addWord("dad");
  wd->addWord("mad");
  assert(!wd->search("pad")); // -> false
  assert(wd->search("bad")); // -> true
  assert(wd->search(".ad")); // -> true
  assert(wd->search("b..")); // -> true
  return 0;
}