#include <iostream>
#include <vector>
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

class Solution {
private:
  int MaxPathSum(TreeNode* root, int& best) {
    if (root == nullptr) return 0;
    int left = MaxPathSum(root->left, best);
    int right = MaxPathSum(root->right, best);
    int best_path = max(root->val, max(root->val + left, root->val + right));
    best = max(best, max(left + root->val + right, best_path));
    return best_path;
  }
public:
  int maxPathSum(TreeNode* root) {
    int best = numeric_limits<int>::min();
    MaxPathSum(root, best);
    return best;
  }
};

int main(void) {
  return 0;
}