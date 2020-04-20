#include <iostream>
#include <vector>
#include <limits>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.size() == 0) return nullptr;
    int idx = 0;
    TreeNode* root = nullptr;
    while (idx < preorder.size()) {
      AddNode(root, new TreeNode(preorder[idx]));
      idx++;
    }
    return root;
  }
private:
  bool AddNode(TreeNode*& root, TreeNode* new_node) {
    if (root == nullptr) {
      root = new_node;
      return true;
    }
    bool added = false;
    if (new_node->val < root->val) {
      added = (root->left == nullptr ? root->left = new_node, true : AddNode(root->left, new_node));
    } else {
      added = (root->right == nullptr ? root->right = new_node, true : AddNode(root->right, new_node));
    }
    return added;
  }
};

void print2D(TreeNode *root, int space = 0, int COUNT = 10) {
  // Base case
  if (root == nullptr) return;
  // Increase distance between levels
  space += COUNT;

  // Process right child
  print2D(root->right, space, COUNT);

  cout << endl;
  for (int i = COUNT; i < space; i++) cout << " ";
  cout << root->val << endl;

  // Process left child
  print2D(root->left, space, COUNT);
}

int main(void) {
  vector<int> preorder = {8,4,1,5,6,10,9,11};
  Solution sol;
  TreeNode* root = sol.bstFromPreorder(preorder);
  print2D(root);
  return 0;
}