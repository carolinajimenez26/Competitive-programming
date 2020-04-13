#include <iostream>
#include <unordered_map>
#include <limits>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int diameterOfBinaryTree(TreeNode* root) {
    unordered_map<TreeNode*, int> deepest;
    if (root == nullptr) return 0;
    int INF = numeric_limits<int>::max();
    int best = -INF;
    Best(root, deepest, best);
    return best;
  }
private:
  void Best(TreeNode* root, unordered_map<TreeNode*, int>& deepest, int& best) {
    if (root == nullptr) {
      return;
    }
    if ((root->left == nullptr && root->right == nullptr)) {
      deepest[root] = 0;
    }
    Best(root->left, deepest, best);
    Best(root->right, deepest, best);
    int deepest_left = root->left ? deepest[root->left] + 1: 0;
    int deepest_right = root->right ? deepest[root->right] + 1: 0;
    int op = deepest_left + deepest_right;
    deepest[root] = max(deepest_left, deepest_right);
    best = max(op, best);
  }
};

int main(void) {
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);

  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(6);

  root->right->left->left = new TreeNode(4);
  root->right->left->right = new TreeNode(5);
  root->right->right->left = new TreeNode(7);

  root->right->left->left->left = new TreeNode(10);
  root->right->left->right->left = new TreeNode(8);
  root->right->left->right->right = new TreeNode(9);
  root->right->right->left->right = new TreeNode(11);

  root->right->left->left->left->right = new TreeNode(11);
  root->right->left->right->right->right = new TreeNode(12);

  Solution sol;
  cout << sol.diameterOfBinaryTree(root) << endl;

  return 0;
}