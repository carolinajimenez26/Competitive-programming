#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Result {
  int height;
  bool height_balanced;
};

class Solution {
private:
  Result getHeight(TreeNode* root) {
    if (root == nullptr) {
      return {0,true};
    }
    Result left = getHeight(root->left);
    Result right = getHeight(root->right);
    int height = 1 + max(left.height, right.height);
    bool height_balance = abs(left.height - right.height) <= 1;
    Result r = {height, height_balance && left.height_balanced && right.height_balanced};
    return r;
  }
public:
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    Result r = getHeight(root);
    return r.height_balanced;
  }
};

int main(void) {
  return 0;
}