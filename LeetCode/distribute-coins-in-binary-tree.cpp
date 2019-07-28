#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int distributeCoinsHandler(TreeNode* node, int& total) {
  if (node == NULL) return 0;
  int excess = node->val - 1;
  excess += distributeCoinsHandler(node->left, total);
  excess += distributeCoinsHandler(node->right, total);
  total += abs(excess);
  return excess;
}

int distributeCoins(TreeNode* root) {
  int total = 0;
  distributeCoinsHandler(root, total);
  return total;
}

int main(void) {
  TreeNode* tn = new TreeNode(1);
  tn->left = new TreeNode(0);
  tn->left->right = new TreeNode(3);
  tn->right = new TreeNode(0);
  cout << distributeCoins(tn) << endl;
  return 0;
}
