#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode* n, int val) {
  if (n->val > val) { // insert left
    if (n->left == NULL) n->left = new TreeNode(val);
    else { // insert it in the left child
      insert(n->left, val);
    }
  } else { // insert right
    if (n->right == NULL) n->right = new TreeNode(val);
    else { // insert it in the right child
      insert(n->right, val);
    }
  }
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
  insert(root, val);
  return root;
}

void print(TreeNode* n) {
  if (n->left != NULL) print(n->left);
  cout << n->val << endl;
  if (n->right != NULL) print(n->right);
}

int main(void) {
  TreeNode* tn = new TreeNode(4);
  insertIntoBST(tn, 2);
  print(tn);
  return 0;
}
