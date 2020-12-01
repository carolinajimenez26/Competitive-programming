#include <iostream>
#include <vector>
#include <map>
#include <limits>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct Node {
  int val;
  vector<Node*> neighs;
  Node(int _val) : val(_val) {};
  void AddNeigh(Node* n) {
    neighs.push_back(n);
  }
};

class Solution {
private:
  int GetHeight(Node* node, Node* parent) {
    if (node == nullptr) return 0;
    int max_height = 0;
    for (auto neigh : node->neighs) {
      if (neigh == parent) {
        continue;
      }
      int height = GetHeight(neigh, node);
      max_height = max(max_height, height);
    }
    return 1 + max_height;
  }
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
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
    map<int, vector<int>> heights;
    for (int i = 0; i < n; i++) {
      // dbg(i);
      int height = GetHeight(nodes[i], nullptr);
      // dbg(height);
      heights[height].push_back(i);
    }
    return heights.begin()->second;
  }
};

struct Test {
  int n;
  vector<vector<int>> edges;
  vector<int> expected;
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

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
    {
      4, {}, {0,1,2,3}
    },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.findMinHeightTrees(test.n, test.edges);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      cout << "Found: " << endl;
      Print(out);
      cout << "Expected: " << endl;
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}