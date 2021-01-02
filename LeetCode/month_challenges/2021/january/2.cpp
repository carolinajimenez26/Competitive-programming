#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (target == nullptr) return nullptr;
    return GetTargetCopy(cloned, target);
  }
private:
  TreeNode* GetTargetCopy(TreeNode* root, TreeNode* target) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val == target->val) {
      return root;
    }
    TreeNode* left = GetTargetCopy(root->left, target);
    if (left != nullptr) {
      return left;
    }
    return GetTargetCopy(root->right, target);
  }
};

int main(void) {
  return 0;
}