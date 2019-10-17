#include <iostream>
#include <queue>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
    vector<int> FindPathToNode(TreeNode* n) {
        vector<int> result;
        while (n != nullptr) {
            result.push_back(n->val);
            n = n->parent;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    void AddChildren(TreeNode*& parent, TreeNode*& child, string position) {
        child->parent = parent;
        if (position == "left") {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }

    void Toggle(string& dir) {
        if (dir == "left") {
            dir = "right";
        } else {
            dir = "left";
        }
    }

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

    vector<int> pathInZigZagTree(int label) {
        if (label == 0) return {};
        string curr_direction = "right";
        vector<TreeNode*> level_nodes;
        TreeNode* root = new TreeNode(1);
        TreeNode* target = new TreeNode(label);
        level_nodes.push_back(root);
        bool finish = false;
        while (!finish) {
            int number_new_nodes = level_nodes.size() * 2;
            vector<TreeNode*> curr_level;
            for (int i = 0, n = level_nodes.back()->val + 1; i < number_new_nodes; i++, n++) {
                TreeNode* node = new TreeNode(n);
                curr_level.push_back(node);
                if (n == label) {
                    target = node;
                }
            }
            string node_position = curr_direction;
            int i = 0;
            while (!level_nodes.empty()) {
                TreeNode* last = level_nodes.back();
                AddChildren(last, curr_level[i], node_position);
                i++;
                Toggle(node_position);
                AddChildren(last, curr_level[i], node_position);
                i++;
                Toggle(node_position);
                level_nodes.pop_back();
            }
            Toggle(curr_direction);
            level_nodes = curr_level;
            if (level_nodes.back()->val >= label) {
                finish = true;
            }
        }
        // print2D(root, 0, 10);
        return FindPathToNode(target);
    }
};

void Print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
}

int main(void) {
    Solution sol;
    vector<int> path = sol.pathInZigZagTree(14);
    Print(path);
    return 0;
}