#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void InsertLeafPaths(map<int, vector<vector<TreeNode*>>>& depth_path, TreeNode* current, int depth, 
                         vector<TreeNode*> path) {
        if (current == nullptr) {
            return;
        }
        path.push_back(current);
        if (current->left == nullptr && current->right == nullptr) { // leaf
            depth_path[depth].push_back(path);
            return;
        }
        InsertLeafPaths(depth_path, current->left, depth + 1, path);
        InsertLeafPaths(depth_path, current->right, depth + 1, path);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) return root;
        map<int, vector<vector<TreeNode*>>> depth_path;
        InsertLeafPaths(depth_path, root, 0, {});

        int max_depth = depth_path.rbegin()->first;
        int path_sizes = depth_path[max_depth][0].size();
        bool finish = false;

        // for every position of the path
        for (int i = 0, last_equal_idx = 0; i < path_sizes && !finish; i++, last_equal_idx++) {
            TreeNode* last_n = new TreeNode(-1);
            for (auto curr_path : depth_path[max_depth]) { // for every path
                if (last_n->val == -1) {
                    last_n = curr_path[i];
                }
                if (curr_path[i] != last_n) {
                    return curr_path[last_equal_idx - 1];
                }
            }
        }
        return depth_path[max_depth][0].back();
    }
};

// Extracted from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print2D(TreeNode *root, int space, int COUNT) {
  // Base case
  if (root == NULL) return;
  // Increase distance between levels
  space += COUNT;

  // Process right child
  print2D(root->right, space, COUNT);

  cout << endl;
  for (int i = COUNT; i < space; i++) cout << " ";
  cout << root->val << endl;

  // Process left child
  print2D(root->left, space, COUNT);
}

int main(void) {
    Solution sol;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    print2D(root, 0, 10);
    cout << endl;

    TreeNode* out = sol.lcaDeepestLeaves(root);
    print2D(out, 0, 10);
    cout << "-------------" << endl;
    root->right->left = new TreeNode(6);
    print2D(root, 0, 10);
    cout << endl;

    out = sol.lcaDeepestLeaves(root);
    print2D(out, 0, 10);

    return 0;
}