#include <iostream>
#include <cmath>
#include <unordered_map>
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
  unordered_map<TreeNode*, int> tilt;

  int Calculate(TreeNode* root) {
    if (root == nullptr) return 0;
    int left_acc = Calculate(root->left);
    int right_acc = Calculate(root->right);
    tilt[root] = abs(left_acc - right_acc);
    return left_acc + right_acc + root->val;
  }
public:
  int findTilt(TreeNode* root) {
    if (root == nullptr) return 0;
    int left_acc = Calculate(root->left);
    int right_acc = Calculate(root->right);
    tilt[root] = abs(left_acc - right_acc);
    int ans = 0;
    for (auto [node, val] : tilt) {
      ans += val;
    }
    return ans;
  }
};

int main(void) {
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right = new TreeNode(9);
  root->right->right = new TreeNode(7);
  Solution sol;
  cout << sol.findTilt(root) << endl;
  return 0;
}