#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool areDifferent(TreeNode* node1, TreeNode* node2) {
  if (node1 == NULL && node2 != NULL) return true;
  if (node2 == NULL && node1 != NULL) return true;
  if (node1 != NULL && node2 != NULL) if (node1->val != node2->val) return true;
  return false;
}

void swap(TreeNode* node) {
  TreeNode* tmp = node->left;
  node->left = node->right;
  node->right = tmp;
}

bool flipEquiv(TreeNode* node1, TreeNode* node2) {
  if (node1 == NULL && node2 == NULL) return true;
  if (areDifferent(node1, node2)) return false;
  if (areDifferent(node1->left, node2->left)) swap(node1);
  return flipEquiv(node1->left, node2->left) && flipEquiv(node1->right, node2->right);
}

int main(void) {

  return 0;
}
