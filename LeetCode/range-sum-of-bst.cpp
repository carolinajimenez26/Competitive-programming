#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBetween(int n, int l, int r) {
  return n >= l && n <= r;
}

int rangeSumBST(TreeNode* root, int L, int R) {
  if (root == nullptr) return 0;
  int count = 0;
  if (isBetween(root->val, L, R)) {
    count += root->val;
  }
  count += rangeSumBST(root->left, L, R);
  count += rangeSumBST(root->right, L, R);
  return count;
}

int main(void) {
  pair<int, int> input = make_pair(7, 15);
  int expectedOutput = 32;
  TreeNode* tn = new TreeNode(10);
  tn->left = new TreeNode(5);
  tn->right = new TreeNode(15);
  tn->left->left = new TreeNode(3);
  tn->left->right = new TreeNode(7);
  tn->right->right = new TreeNode(18);
  int output = rangeSumBST(tn, input.first, input.second);
  if (expectedOutput == output)
    cout << "Good Job" << endl;
  else cout << "Keep trying" << endl;
  // cout << output << endl;
  return 0;
}
