#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Result {
  int height;
  bool balanced;
};

class Solution {
public:
  bool isBalanced(TreeNode* root) {
    return IsBalanced(root).balanced;
  }
private:
  Result IsBalanced(TreeNode* root) {
    if (root == nullptr) {
      return {0,true};
    }
    Result left = IsBalanced(root->left);
    Result right = IsBalanced(root->right);
    int height = max(left.height, right.height) + 1;
    bool is_balanced = left.balanced && right.balanced && 
                       (abs(left.height - right.height) <= 1);
    return {height, is_balanced};
  }
};

int main(void) {
  return 0;
}