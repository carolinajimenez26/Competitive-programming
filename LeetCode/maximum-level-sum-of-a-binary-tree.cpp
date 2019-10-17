#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q_current;
        q_current.push(root);
        int max_count = 0, max_level = 0, curr_level = 1;
        while (!q_current.empty()) {
            queue<TreeNode*> q_level;
            int level_sum = 0;
            while (!q_current.empty()) {
                TreeNode* current_node = q_current.front();
                level_sum += current_node->val;
                if (current_node->left != nullptr) {
                    q_level.push(current_node->left);
                }
                if (current_node->right != nullptr) {
                    q_level.push(current_node->right);
                }
                q_current.pop();
            }
            if (level_sum > max_count) {
                max_count = level_sum;
                max_level = curr_level;
            }
            q_current = q_level;
            curr_level++;
        }
        return max_level;
    }
};

int main(void) {
    return 0;
}