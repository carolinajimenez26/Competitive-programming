// #include <bits/stdc++.h> // Linux
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <limits>
#include <iomanip>      // std::setprecision
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define INF numeric_limits<int>::max()
using int64 = long long int;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int ToNum(char &s) {
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

vector<string> Split(string &s) {
  stringstream ss;
  ss << s;
  vector<string> v;
  string tok;
  while (ss >> tok)
    v.push_back(tok);
  return v;
}

vector<string> Split(string s, char tok) { // split a string by an  especified token
	istringstream ss(s);
  string token;
  vector<string> v;

  while(getline(ss, token, tok)) {
    v.push_back(token);
  }

  return v;
}

template <class T>
void Print(T v) {
  for (auto i : v) cout << i << " ";
  cout << endl;
}

// Extracted from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void Print2D(TreeNode *root, int space = 0, int COUNT = 10) {
  // Base case
  if (root == nullptr) return;
  // Increase distance between levels
  space += COUNT;

  // Process right child
  Print2D(root->right, space, COUNT);

  cout << endl;
  for (int i = COUNT; i < space; i++) cout << " ";
  cout << root->val << endl;

  // Process left child
  Print2D(root->left, space, COUNT);
}


TreeNode* Build(vector<string>& tree) { // builds a Tree given a vector
  if (tree.empty()) return nullptr;
  vector<TreeNode*> nodes;
  for (int i = 0; i < tree.size(); i++) {
    if (tree[i] == "null") {
      nodes.push_back(nullptr);
    } else {
      int val = stoi(tree[i]);
      TreeNode* node = new TreeNode(val);
      nodes.push_back(node);
    }
  }

  for (int i = 0; i < tree.size(); i++) {
    if (2 * i + 1 < tree.size()) nodes[i]->left = nodes[2 * i + 1];
    if (2 * i + 1 < tree.size()) nodes[i]->right = nodes[2 * i + 2];
  }
  return nodes[0];
}

vector<string> Convert(TreeNode* root) { // converts a tree to a vector of strings
  vector<string> ans;
  if (root == nullptr) return ans;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();
    if (curr == nullptr) {
      ans.push_back("null");
      continue;
    }
    ans.push_back(to_string(curr->val));
    q.push(curr->left);
    q.push(curr->right);
  }
  while (ans.back() == "null") {
    ans.pop_back();
  }
  return ans;
}

struct Test {
  int n, ans;
};

int main(int argc, char const *argv[]) {
  // Accelerates the standar input
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(6) << 30.5 << endl; // 30.500000

  // Testing
  vector<Test> tests = { // you should define your Test structure
    { 1, 2 },
    { 2, 3 },
  };
  int tc = 0;
  bool succeed = true;
  auto Increment = [](int n) { // An inline function definition just to show an example
    return n + 1;
  };
  for (auto test : tests) {
    int out = Increment(test.n); // you should replace Increment for your Solver function
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;

  return 0;
}
