#include <iostream>
#include <vector>
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
private:
  TreeNode* RemoveNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    if (root->val == key) {
      return RemoveNode(root);
    }
    if (key < root-> val) {
      root->left = RemoveNode(root->left, key);
    } else {
      root->right = RemoveNode(root->right, key);
    }
    return root;
  }

  TreeNode* RemoveNode(TreeNode* root) {
    if ((root->left == nullptr) && (root->right == nullptr)) {
      delete root;
      return nullptr;
    }
    TreeNode* left_tree = root->left;
    TreeNode* right_tree = root->right;
    delete root;
    if (right_tree == nullptr) return left_tree;

    TreeNode* curr = right_tree;
    while (curr->left != nullptr) {
      curr = curr->left;
    }
    curr->left = left_tree;
    return right_tree;
  }

public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    return RemoveNode(root, key);
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

void Print(const vector<string>& vs) {
  for (auto s : vs) cout << s << ", ";
  cout << endl;
}

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

struct Test {
  vector<string> tree;
  int key;
  vector<string> ans;
};

int main(void) {
  vector<Test> tests = {
    { {}, 30, {} },
    {
      {"50", "30", "60", "20", "40", "null", "70", "10", "25", "35", "45"}, 
      30,
      {"50", "40", "60", "35", "45", "null", "70", "20", "null", "null", "null", "null", "null", "10", "25"} 
    },
    { 
      {"50", "30", "60", "20", "40", "null", "70", "10", "25", "35", "45"}, 
      50,
      {"60", "30", "70", "20", "40", "null", "null", "10", "25", "35", "45"} 
    },
    { 
      {"50", "30", "60", "20", "40", "null", "70", "10", "25", "35", "45"}, 
      45,
      {"50", "30", "60", "20", "40", "null", "70", "10", "25", "35"} 
    },
    { 
      {"50", "30", "60", "20", "40", "null", "70", "10", "25", "35", "45"}, 
      100,
      {"50", "30", "60", "20", "40", "null", "70", "10", "25", "35", "45"} 
    },
    { 
      {"50", "30", "60", "null", "45", "55", "70", "40", "49"}, 
      30,
      {"50", "45", "60",  "40", "49", "55", "70"} 
    },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    TreeNode *out = sol.deleteNode(Build(test.tree), test.key);
    if (Convert(out) != test.ans) {
      cout << "Failed on test #" << tc << ". Found: " << endl;
      Print(Convert(out));
      Print2D(out);
      cout << "Expected: " << endl;
      Print(test.ans);
      Print2D(Build(test.ans));
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl; 
  return 0;
}