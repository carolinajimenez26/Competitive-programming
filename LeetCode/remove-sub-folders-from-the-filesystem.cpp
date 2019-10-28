#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <cstring>

using namespace std;

class Node {
private:
  unordered_map<string, Node*> edges;
  bool is_finalizer;
public:
  Node() : edges(), is_finalizer(false) {};
  
  void Add(const vector<string>& vs, int idx) {
    if (idx == vs.size()) {
      this->is_finalizer = true;
      return;
    }
    string s = vs[idx];
    if (this->edges.count(s) == 0) this->edges[s] = new Node();
    this->edges[s]->Add(vs, idx + 1);
  }

  bool IsFinalNode() {
    return this->is_finalizer;
  }

  unordered_map<string, Node*> GetEdges() {
    return this->edges;
  }

  void Print() {
    for (auto edge : edges) {
      cout << edge.first << endl;
      if (!is_finalizer) {
        edge.second->Print();
      }
    }
    cout << endl;
  }
};

class Solution {
private:
  Node* prefix_tree;

  vector<string> Split(string s, char tok) {
    istringstream ss(s);
    string token;
    vector<string> v;

    while(getline(ss, token, tok)) {
      if (token != "") v.push_back(token);
    }

    return v;
  }

  void Print(const vector<string>& vs) {
    for (auto s : vs) cout << s << " ";
    cout << endl;
  }
public:
  void DFS(Node* n, string curr, vector<string>& result) {
    if (n->IsFinalNode()) {
      result.push_back(curr);
      return;
    }
    for (auto edge : n->GetEdges()) {
      DFS(edge.second, curr + '/' + edge.first, result);
    }
  }

  vector<string> removeSubfolders(vector<string>& folder) {
    prefix_tree = new Node();
    for (auto s : folder) {
      vector<string> curr = Split(s, '/');
      // Print(curr);
      prefix_tree->Add(curr, 0);
    }
    // prefix_tree->Print();
    vector<string> result;
    DFS(prefix_tree, "", result);
    return result;
  }
};

struct Test {
  vector<string> input;
  vector<string> expected;
};

void Print(const vector<string>& vs) {
  for (auto s : vs) cout << s << " ";
  cout << endl;
}

int main(void) {
  vector<Test> tests = {
    {
      {"/a/b/c","/a/b/ca","/a/b/d"},
      {"/a/b/c","/a/b/ca","/a/b/d"}
    },
    {
      {"/a","/a/b/c","/a/b/d"},
      {"/a"}
    },
    {
      {"/a","/a/b","/c/d","/c/d/e","/c/f"},
      {"/a","/c/d","/c/f"}
    }
  };
  bool succeed = true;
  int tc = 0;
  for (auto test : tests) {
    Solution sol;
    vector<string> out = sol.removeSubfolders(test.input);
    if (out != test.expected) {
      succeed = false;
      cout << "Failed on test #" << tc << endl;
      cout << "Got: " << endl;
      Print(out);
      cout << "Expected " << endl;
      Print(test.expected);
    }
    tc++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}