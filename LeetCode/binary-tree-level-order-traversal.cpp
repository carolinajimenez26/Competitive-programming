#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void levelOrder(TreeNode* node, int depth, vector<vector<int>>& result) {
        if (node == nullptr) return;
        if (result.size() == 0) {
            result.push_back({node->val});
        } else {
            if (result.size() > depth) {
                result[depth].push_back(node->val);
            } else {
                result.push_back({node->val});
            }
        }
        levelOrder(node->left, depth + 1, result);
        levelOrder(node->right, depth + 1, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(root, 0, result);
        return result;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
