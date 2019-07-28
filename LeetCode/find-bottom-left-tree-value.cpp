#include <iostream>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* node) {
  return node->left == NULL && node->right == NULL;
}

void findBottomLeftValueHandler(TreeNode* node, int& result,
                                int& result_depth, int depth, bool isLeftChild) {

  if (node == NULL) return;
  if (isLeaf(node) && depth > result_depth) {
      result_depth = depth;
      result = node->val;
  } else {
    findBottomLeftValueHandler(node->left, result, result_depth, depth + 1, true);
    findBottomLeftValueHandler(node->right, result, result_depth, depth + 1, false);
  }
}

int findBottomLeftValue(TreeNode* root) {
  int result = root->val, result_depth = 0;
  findBottomLeftValueHandler(root, result, result_depth, 0, true);
  return result;
}

int main(void) {
  // TreeNode* tn = new TreeNode(1);
  // tn->left = new TreeNode(2);
  // tn->left->left = new TreeNode(4);
  //
  // tn->right = new TreeNode(3);
  // tn->right->left = new TreeNode(5);
  // tn->right->left->left = new TreeNode(7);
  // tn->right->right = new TreeNode(6);

  TreeNode* tn = new TreeNode(3);
  tn->left = new TreeNode(1);
  tn->left->left = new TreeNode(0);
  tn->left->right = new TreeNode(0);

  tn->right = new TreeNode(5);
  tn->right->left = new TreeNode(4);
  tn->right->right = new TreeNode(6);

  cout << findBottomLeftValue(tn) << endl;
  return 0;
}
