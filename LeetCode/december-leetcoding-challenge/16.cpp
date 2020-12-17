#include <iostream>
#include <limits>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using int64 = long long int;

class Solution {
private:
  const int64 INF = numeric_limits<int64>::max();

  bool isValidBST(TreeNode* root, int64 last_left, int64 last_right) {
    if (root == nullptr) return true;
    int is_valid = root->val > last_right && root->val < last_left;
    if (!is_valid) return false;
    return isValidBST(root->left, root->val, last_right) &&
           isValidBST(root->right, last_left, root->val);
  }  
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root->left, root->val, -INF) &&
           isValidBST(root->right, INF, root->val);
  }
};

int main(void) {
  return 0;
}