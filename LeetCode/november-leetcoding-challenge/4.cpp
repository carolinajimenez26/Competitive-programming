#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node {
  int val;
  int deep;
  Node* parent;

  vector<Node*> neighs;
  Node(int _val) : val(_val), deep(1), parent(nullptr) {};
  void AddNeigh(Node* n) {
    neighs.push_back(n);
  }

  void PrepareDfs() {
    parent = this;
    deep = 1;
  }

  Node* ChooseDeepest(Node* other) {
    if (other == nullptr || other->deep <= deep) {
      return this;
    }
    return other;
  }
};

class Solution {
private:
  // Runtime: O(# nodes + edges)
  // Space: O(largest branch)
  Node* GetDeepestNodeFrom(Node* node) {
    if (node == nullptr) return nullptr;
    Node* ans = node;
    for (auto &neigh : node->neighs) {
      if (neigh == node->parent) {
        continue;
      }
      neigh->parent = node;
      neigh->deep = node->deep + 1;
      ans = ans->ChooseDeepest(GetDeepestNodeFrom(neigh));
    }
    return ans;
  }

  // Runtime: O(# nodes)
  // Space: O(# nodes)
  vector<int> BuildPath(Node *current) {
    vector<int> ans;
    while (current->parent != current) {
      ans.push_back(current->val);
      current = current->parent;
    }
    ans.push_back(current->val);
    return ans;
  }

public:
  void Print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }

  // Runtime: O(# nodes + edges)
  // Space: O(# nodes + edges)
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 0) return {};
    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
      nodes[i] = new Node(i);
    }
    for (auto edge : edges) {
      Node* a = nodes[edge[0]];
      Node* b = nodes[edge[1]];
      a->AddNeigh(b);
      b->AddNeigh(a);
    }

    for (auto &node : nodes) {
      node->PrepareDfs();
    }
    Node* origin = GetDeepestNodeFrom(nodes[0]);
    for (auto &node : nodes) {
      node->PrepareDfs();
    }
    Node* end = GetDeepestNodeFrom(origin);
    vector<int> path = BuildPath(end);
    vector<int> ans;
    int mid = path.size() / 2;
    if (path.size() % 2 == 0) { // there are 2 middles
      ans.push_back(path[mid - 1]);
    }
    ans.push_back(path[mid]);
    return ans;
  }
};

struct Test {
  int n;
  vector<vector<int>> edges;
  vector<int> expected;
};

int main(void) {
  vector<Test> tests ={
    {
      4, {{1,0},{1,2},{1,3}}, {1}
    },
    {
      6, {{3,0},{3,1},{3,2},{3,4},{5,4}}, {3,4}
    },
    {
      1, {}, {0}
    },
    {
      2, {{0,1}}, {0,1}
    },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.findMinHeightTrees(test.n, test.edges);
    set<int> out_set(out.begin(), out.end());
    set<int> test_expected_set(test.expected.begin(), test.expected.end());
    if (out_set != test_expected_set) {
      cout << "Failed on test #" << tc << endl;
      cout << "Found: " << endl;
      sol.Print(out);
      cout << "Expected: " << endl;
      sol.Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}