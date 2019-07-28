#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* n) {
  return n->left == NULL && n->right == NULL;
}

TreeNode* pruneTree(TreeNode* root) {
  if (root == NULL) {
      return root;
  }
  root->left = pruneTree(root->left);
  root->right = pruneTree(root->right);
  if (isLeaf(root) && root->val == 0) {
      delete root;
      root = NULL;
  }
  return root;
}

int main(void) {
  TreeNode* tn = new TreeNode(0);
  tn->left = new TreeNode(1);
  tn->left->left = new TreeNode(0);
  tn->left->left->left = new TreeNode(0);
  tn->left->left->right = new TreeNode(0);

  tn->right = new TreeNode(0);
  tn->right->right = new TreeNode(1);
  tn->right->right->left = new TreeNode(1);
  tn->right->right->right = new TreeNode(1);

  TreeNode* pruned = pruneTree(tn);

  delete tn;
  delete pruned;

  return 0;
}
