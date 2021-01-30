#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

// h -> e -> l -> l -> o -> 
//   -> a -> l -> l -> o -> 
//   -> i -> l -> a -> m ->
// holax
class Node {
public:
  int freq;
  bool is_final_node;
  unordered_map<char, Node*> edges;
  Node() : freq(0), is_final_node(false) {}

  void AddNeigh(char c, Node* node) {
    edges[c] = node;
  }

  bool HasNeigh(char c) {
    return edges.count(c) > 0;
  }

  Node* GetNeigh(char c) {
    return edges.count(c) ? edges[c] : nullptr;
  }
};

class MagicDictionary {
public:
  /** Initialize your data structure here. */
  MagicDictionary() {
    trie = new Node();
  }
  
  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    for (auto word : dict) {
      Add(word, 0, trie);
    }
  }
  
  /*
  * Returns if there is any word in the trie that equals to the given word 
  * after modifying exactly one character
  */
  bool search(string word) {
    return MatchWithDiff(1, word, 0, trie, 0);
  }
private:
  Node* trie;

  void Add(const string &word, int idx, Node* node) {
    node->freq++;
    if (idx == word.size()) {
      node->is_final_node = true;
      return;
    }
    if (!node->HasNeigh(word[idx])) {
      node->AddNeigh(word[idx], new Node());
    }
    Add(word, idx + 1, node->GetNeigh(word[idx]));
  }

  bool MatchWithDiff(int expected_diff, const string &word, int idx, Node* node, int curr_diff) {
    if (idx == word.size()) {
      if (node->is_final_node) {
        return curr_diff == expected_diff;
      }
      return false; // didn't consume any word in dict
    }
    if (curr_diff > expected_diff) {
      return false;
    }
    for (auto [letter, neigh] : node->edges) {
      int next_diff = curr_diff;
      if (letter != word[idx]) {
        next_diff++;
      }
      if (MatchWithDiff(expected_diff, word, idx + 1, neigh, next_diff)) {
        return true;
      }
    }
    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */

int main(void) {
  vector<string> dict = {"hello","hallo","leetcode"};
  MagicDictionary magic_dict;
  magic_dict.buildDict(dict);
  dbg(magic_dict.search("hello"));
  dbg(magic_dict.search("hllo"));
  dbg(magic_dict.search("hallo"));
  dbg(magic_dict.search("xxllo"));
  return 0;
}