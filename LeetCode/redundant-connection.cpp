#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<int, set<int>> Graph;
  vector<bool> visited;
public:
  bool DFS(int node, unordered_map<int, int>& parent) {
    visited[node] = true;
    for (auto neigh : Graph[node]) {
      if (visited[neigh]) {
        if (parent[node] != neigh) { // if it is not my parent
          return true; // there is a cycle
        }
      } else {
        parent[neigh] = node;
        if (DFS(neigh, parent)) {
          return true;
        }
      }
    }
    return false;
  }

  bool HasCycles() {
    unordered_map<int, int> parent;
    for (auto e : Graph) {
      int n = e.first;
      if (!visited[n]) {
        if (DFS(n, parent)) {
          return true;
        }
      }
    }
    return false;
  }

  void Print() {
    for (auto e : Graph) {
      cout << e.first << " -> ";
      for (auto neigh : e.second) {
        cout << neigh << " ";
      }
      cout << endl;
    }
  }

  void Print(const vector<bool>& v) {
    for (auto e : v) {
      cout << e << " ";
    }
    cout << endl;
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    for (auto edge : edges) {
      int n = edge[0], v = edge[1];
      Graph[n].insert(v);
      Graph[v].insert(n);
    }

    for (int i = edges.size() - 1; i >= 0; i--) {
      visited.assign(Graph.size() + 1, false);
      vector<int> edge = edges[i];
      int n = edge[0], v = edge[1];
      Graph[n].erase(v);
      Graph[v].erase(n);
      if (!HasCycles()) {
        return {n, v};
      }
      Graph[n].insert(v);
      Graph[v].insert(n);
    }

    return {-1, -1}; // error
  }
};

struct Test {
  vector<vector<int>> edges;
  vector<int> expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {{1,4},{3,4},{1,3},{1,2},{4,5}},
      {1,3}
    },
    {
      {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}},
      {1,4}
    },
    {
      {{1,2}, {1,3}, {2,3}},
      {2,3}
    }
  };
  bool succeed = true;

  int test_case = 0;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.findRedundantConnection(test.edges);
    if (out != test.expected) {
      succeed = false;
      cout << "Failed on test #" << test_case << endl;
      cout << "Got: " << out[0] << ", " << out[1] << endl;
      cout << "Expected: " << test.expected[0] << ", " << test.expected[1] << endl;
    }
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}