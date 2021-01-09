#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

struct Node {
  string val;
  vector<Node*> neighs;
  Node* parent;
  bool visited;

  Node(const string& s): val(s), visited(false) {
    parent = nullptr;
  }

  bool operator!=(const Node& other) const {
    return val != other.val;
  }
};

class Solution {
public:
  int ladderLength(string begin_word, string end_word, vector<string>& word_list) {
    if (word_list.empty() || 
        (find(word_list.begin(), word_list.end(), end_word) == word_list.end())
       ) {
      return 0;
    }
    if (find(word_list.begin(), word_list.end(), begin_word) == word_list.end()) {
      word_list.push_back(begin_word);
    }
    vector<Node*> graph = CreateGraph(word_list);
    // Print(graph);
    Node* source = Find(graph, begin_word);
    assert("source cannot be nullptr" && source != nullptr);
    VisitNodes(source);
    Node* target = Find(graph, end_word);
    assert("target cannot be nullptr" && target != nullptr);
    int ans = GetPathSize(target, source);
    if (ans == INF) {
      return 0;
    }
    return ans;
  }
private:
  const int INF = 6000;

  void Print(const vector<Node*>& graph) {
    for (auto node : graph) {
      cout << node->val << "->";
      for (auto neigh : node->neighs) {
        cout << neigh->val << ", ";
      }
      cout << endl;
    }
  }

  Node* Find(const vector<Node*>& graph, const string& target) {
    for (auto node : graph) {
      if (node->val == target) {
        return node;
      }
    }
    return nullptr;
  }

  int GetPathSize(Node* from, Node* to) {
    int ans = 0;
    if (from == nullptr || to == nullptr) {
      return ans;
    }
    Node* curr = from;
    while (curr != nullptr && curr != to) {
      ans++;
      curr = curr->parent;
    }
    if (curr != to) {
      return INF;
    }
    return ans + 1;
  }

  vector<Node*> CreateGraph(const vector<string>& word_list) {
    vector<Node*> graph;
    for (auto s : word_list) {
      graph.push_back(new Node(s));
    }
    for (int i = 0; i < word_list.size(); i++) {
      for (int j = i + 1; j < word_list.size(); j++) {
        if (DifferByOne(word_list[i], word_list[j])) {
          graph[i]->neighs.push_back(graph[j]);
          graph[j]->neighs.push_back(graph[i]);
        }
      }
    }
    return graph;
  }

  bool DifferByOne(const string& a, const string& b) {
    if (a == b || a.size() != b.size()) {
      return false;
    }
    int diff = 0;
    for (int i = 0; i < a.size() && diff <= 1; i++) {
      if (a[i] != b[i]) {
        diff++;
      }
    }
    return diff == 1;
  }

  void VisitNodes(Node* source) {
    if (source == nullptr) {
      return;
    }
    queue<Node*> q;
    source->visited = true;
    q.push(source);

    while(!q.empty()) {
      Node* curr = q.front();
      q.pop();
      for(auto neigh : curr->neighs) {
        if (!neigh->visited) {
          neigh->visited = true;
          neigh->parent = curr;
          q.push(neigh);
        }
      }
    }
  }
};

struct Test {
  string begin_word, end_word;
  vector<string> word_list;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { "hit", "cog", {"hot","dot","dog","lot","log","cog"}, 5 },
    { "hit", "cog", {"hot","dot","dog","lot","log"}, 0 },
    { "hit", "cog", {"a","b","dit","cde","dig", "cig", "cog"}, 5 },
    { "hit", "cog", {"a","b","cde"}, 0 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.ladderLength(test.begin_word, test.end_word, test.word_list);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out 
           << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}