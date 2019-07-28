#include <iostream>
#define dbg(x) cout << #x << ": " << (x) << endl

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteNodes(TreeNode *node) {
  if (node == nullptr)
    return;
  deleteNodes(node->left);
  deleteNodes(node->right);
  delete node;
}

TreeNode *trimBST(TreeNode *node, int L, int R) {
  if (node == nullptr) return nullptr;
  if (node->val < L) {
    deleteNodes(node->left);
    auto *ans = trimBST(node->right, L, R);
    // delete node;
    return ans;
  }
  if (node->val > R) {
    deleteNodes(node->right);
    auto *ans = trimBST(node->left, L, R);
    // delete node;
    return ans;
  }
  node->left = trimBST(node->left, L, R);
  node->right = trimBST(node->right, L, R);
  return node;
}

int main(void) {
  TreeNode *root = new TreeNode(5);

  root->left = new TreeNode(2);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  root->right = new TreeNode(6);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(7);

  print2D(root, 0, 10);

  root = trimBST(root, 2, 3);
  dbg(root->val);
  print2D(root, 0, 10);

  return 0;
}
