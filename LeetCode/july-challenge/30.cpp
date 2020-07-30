#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

template <class T>
void Print(T v) {
  for (auto e : v) cout << e << ", ";
  cout << endl;
}

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

public:
  Trie() {
    root = new Node();
  }

  void Add(const string &s) {
    Add(root, s, 0);
  }

  bool Exists(const char letter, Node *search_node) {
    if (search_node->edges.count(letter) == 0) {
      return false;
    }
    return true;
  }

  bool IsFinalNode(Node *search_node) {
    return search_node->final_node;
  }

  Node* MoveForward(Node *search_node, const char letter) {
    if (search_node == nullptr) return nullptr;
    return  search_node->edges.count(letter) ? search_node->edges[letter] : nullptr;
  }

  Node* CreateSearchNode() {
    return root;
  }
};

class Solution {
private:
  Trie trie;
  unordered_map<int, vector<string>> memo;

  vector<string> Concat(const string& s, vector<string>& v) {
    vector<string> ans;
    for (auto words : v) {
      ans.push_back(s + words);
    }
    return ans;
  }

  void Insert(vector<string>& a, const vector<string>& b) {
    for (auto s : b) {
      a.push_back(s);
    }
  }

  vector<string> wordBreak(const string& s, int from, Node* search_node) {
    if (from == s.size()) {
      return {"$"};
    }
    if (memo.count(from) > 0) return memo[from];
    int i = from;
    string tmp;
    while (i < s.size() && trie.Exists(s[i], search_node)) {
      tmp.push_back(s[i]);
      search_node = trie.MoveForward(search_node, s[i]);
      if (trie.IsFinalNode(search_node)) {
        vector<string> partial = wordBreak(s, i + 1, trie.CreateSearchNode());
        if (!partial.empty()) {
          tmp.push_back(' ');
          Insert(memo[from], Concat(tmp, partial));
          tmp.pop_back();
        }
      }
      i++;
    }
    return memo[from];
  }

public:
  vector<string> wordBreak(string s, vector<string>& words) {
    if (s.empty() || words.empty()) return {};
    for (auto word : words) trie.Add(word);
    // trie.Print();
    vector<string> ans = wordBreak(s, 0, trie.CreateSearchNode());
    for (auto& word : ans) {
      word.pop_back();
      word.pop_back();
    }
    return ans;
  }
};

struct Test {
  string s;
  vector<string> words;
  vector<string> ans;
};

bool Equals(vector<string>& a, vector<string>& b) {
  if (a.size() != b.size()) return false;
  unordered_set<string> a_map;
  for (auto s : a) a_map.insert(s);
  for (auto s : b) {
    if (a_map.count(s) == 0) return false;
  }
  return true;
}

int main(void) {
  vector<Test> tests = {
    { "catsanddog", {"cat", "cats", "and", "sand", "dog"}, {"cats and dog", "cat sand dog"} },
    { "pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"}, {"pine apple pen apple", "pineapple pen apple", "pine applepen apple"} },
    { "catsandog", {"cats", "dog", "sand", "and", "cat"}, {} },
    { "catsanddog", {}, {} },
    { "", {"cat", "cats", "and", "sand", "dog"}, {} },
    { "bb", {"a","b","bbb","bbbb"}, {"b b"} },
    { "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}, {} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<string> out = sol.wordBreak(test.s, test.words);
    if (!Equals(out, test.ans)) {
      cout << "Failed on test #" << tc << ". Found: ";
      Print(out); 
      cout << "Expected: "; 
      Print(test.ans);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}