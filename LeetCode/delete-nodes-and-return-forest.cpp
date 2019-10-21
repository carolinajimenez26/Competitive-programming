#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
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
    TreeNode* DeleteNodeAndReturnNewRoots(TreeNode*& root, int to_delete, vector<TreeNode*>& new_roots) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == to_delete) {
            if (root->left != nullptr) {
                new_roots.push_back(root->left);
            }
            if (root->right != nullptr) {
                new_roots.push_back(root->right);
            }
            root->left = nullptr;
            root->right = nullptr;
            root = nullptr;
            delete root;
            return nullptr;
        }
        root->left = DeleteNodeAndReturnNewRoots(root->left, to_delete, new_roots);
        root->right = DeleteNodeAndReturnNewRoots(root->right, to_delete, new_roots);
        return root;
    }

    // O (nodes^2)
    vector<TreeNode*> delNodesSlow(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> roots = {root};
        for (int i = 0; i < to_delete.size(); i++) { // O (nodes)
            vector<TreeNode*> to_add, new_roots;
            for (auto& node : roots) { // O (nodes)
                int val = node->val;
                DeleteNodeAndReturnNewRoots(node, to_delete[i], to_add);
                if (to_add.size() > 0) {
                    break;
                }
            }
            for (auto node : roots) { // O (nodes)
                if (node != nullptr) {
                    new_roots.push_back(node);
                }
            }
            roots = new_roots;
            for (auto node : to_add) { // O (nodes)
                roots.push_back(node);
            }
        }
        return roots;
    }

    void GetParentsInfo(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parents) {
        if (root == nullptr) return;
        parents[root] = parent;
        GetParentsInfo(root->left, root, parents);
        GetParentsInfo(root->right, root, parents);
    }

    // O ((nodes) * (log nodes))
    vector<TreeNode*> FindValidRoots(const set<TreeNode*>& roots, unordered_map<TreeNode*, TreeNode*>& parents) {
        vector<TreeNode*> result;
        for (auto node : roots) { // O (nodes)
            TreeNode* parent = parents[node];
            if (roots.find(parent) == roots.end()) { // O (log nodes)
                result.push_back(node);
            }
        }
        return result;
    }

    void DeleteChild(TreeNode*& child, unordered_map<TreeNode*, TreeNode*>& parents) {
        TreeNode* parent = parents[child];
        if (parent == nullptr) return;
        if (parent->left == child) {
            parent->left = nullptr;
        } 
        if (parent->right == child) {
            parent->right = nullptr;
        }
    }

    // O ((nodes + edges) * (log nodes))
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<TreeNode*> roots;
        set<int> to_remove(to_delete.begin(), to_delete.end()); // O (nodes)
        unordered_map<TreeNode*, TreeNode*> parents; 
        GetParentsInfo(root, nullptr, parents); // O (nodes)
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) { // O (nodes + edges)
            TreeNode* curr = q.front();
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
            if (to_remove.find(curr->val) == to_remove.end()) { // O (log nodes)
                roots.insert(curr);
            } else {
                curr->left = nullptr;
                curr->right = nullptr;
                DeleteChild(curr, parents);
                curr = nullptr;
            }
            q.pop();
        }
        return FindValidRoots(roots, parents); // O ((nodes) * (log nodes))
    }
};

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
    vector<int> to_delete = {2};
    Solution sol;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    print2D(root, 0, 10);

    vector<TreeNode*> out = sol.delNodes(root, to_delete);

    for (auto node : out) {
        cout << "-----------------" << endl;
        print2D(node, 0, 10);
    }

    return 0;
}