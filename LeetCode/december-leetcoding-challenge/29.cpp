#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int pseudoPalindromicPaths(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    freqs[root->val]++;
    if (IsLeaf(root)) {
      bool ans = IsPalindrome();
      freqs[root->val]--;
      return ans;
    }
    int left = pseudoPalindromicPaths(root->left);
    int right = pseudoPalindromicPaths(root->right);
    freqs[root->val]--;
    return left + right;
  }
private:
  unordered_map<int, int> freqs;

  void Print() {
    for (auto [num, freq] : freqs) cout << num << "->" << freq << endl;
  }

  bool IsLeaf(TreeNode* root) {
    return root != nullptr && root->left == nullptr && root->right == nullptr;
  }

  bool IsPalindrome() {
    bool have_odd = false;
    for (auto [num, freq] : freqs) {
      if (freq == 0) continue;
      if (freq % 2 != 0) {
        if (have_odd) return false;
        have_odd = true;
      }
    }
    return true;
  }
};

TreeNode* Build(vector<string>& tree) { // builds a Tree given a vector
  if (tree.empty()) return nullptr;
  auto CreateNode = [](string s) -> TreeNode* {
    if (s == "null") return nullptr;
    return new TreeNode(stoi(s));
  };
  TreeNode *root = CreateNode(tree[0]);
  queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  
  while (!q.empty()) {
    queue<TreeNode*> next_nodes;
    while (!q.empty()) {
      TreeNode* curr = q.front();
      q.pop();
      if (i < tree.size()) {
        TreeNode* left = CreateNode(tree[i]);
        i++;
        curr->left = left;
        if (left != nullptr) next_nodes.push(left);
      } 
      if (i < tree.size()) {
        TreeNode* right = CreateNode(tree[i]);
        i++;
        curr->right = right;
        if (right != nullptr) next_nodes.push(right);
      } 
    }
    q = next_nodes;
  }
  return root;
}

struct Test {
  vector<string> tree;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {"2","1","1","1","2","null","null","null","null","null","3"}, 1 },
    { {"2","3","1","3","1","null","1"}, 2 },
    { {"1"}, 1 },
    { {"1","2"}, 0 },
    { {"2","1","1","1","3","null","null","null","null","null","1"}, 1 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.pseudoPalindromicPaths(Build(test.tree));
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}