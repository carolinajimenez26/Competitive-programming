#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:

    bool isLeaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    pair<int, int> maxAncestorDiffHandler(TreeNode* node, int& ans) {
        if (node == nullptr) {
            return {100005, -1};
        }
        if (isLeaf(node)) {
            return {node->val, node->val};
        }
        pair<int, int> left = maxAncestorDiffHandler(node->left, ans);
        pair<int, int> right = maxAncestorDiffHandler(node->right, ans);

        int min_n = min(left.first, right.first);
        int max_n = max(left.second, right.second);

        ans = max(ans, abs(node->val - min_n));
        ans = max(ans, abs(node->val - max_n));

        return {min(min_n, node->val), max(max_n, node->val)};
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = -1, ans_left = -1, ans_right = -1;
        pair<int, int> left = maxAncestorDiffHandler(root->left, ans);
        pair<int, int> right = maxAncestorDiffHandler(root->right, ans);

        if (root->left != NULL) {
            ans_left = max(abs(root->val - left.first), abs(root->val - left.second));
        }
        if (root->right != NULL) {
            ans_right = max(abs(root->val - right.first), abs(root->val - right.second));
        }
        
        return isLeaf(root) ? 0 : max(max(ans_left, ans_right), ans);
    }
};

int main(int argc, char const *argv[]) {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    
    root->right->right = new TreeNode(14);

    root->right->right->left = new TreeNode(13);

    Solution sol;
    cout << sol.maxAncestorDiff(root) << endl;

    return 0;
}
