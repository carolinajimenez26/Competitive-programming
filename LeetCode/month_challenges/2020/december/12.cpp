#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
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
  map<int, vector<TreeNode*>> deep_values;
  unordered_map<TreeNode*, TreeNode*> parents;

  // Let n = all nodes in the tree
  // Runtime: O(n)
  // Space: O(n)
  void GetDeepValues(TreeNode* root, TreeNode* parent, int deep) {
    if (root == nullptr) return;
    GetDeepValues(root->left, root, deep + 1);
    GetDeepValues(root->right, root, deep + 1);
    deep_values[deep].push_back(root);
    parents[root] = parent;
  }

  // Worst case scenareo is when the root is the LCA
  // Let d = high of the tree (deepest node).
  // We'll have in curr_nodes: 2^d + 2^(d-1) + 2^(d-2) + ... + 2^0
  // if the tree is balanced, d = log n
  // => n + n / 2 + n / 4 + ... 1
  // Runtime: O(n)
  // Space: O(2^d) = O(n)
  TreeNode* GetLCA(const vector<TreeNode*>& deepest_nodes) {
    set<TreeNode*> curr_nodes(deepest_nodes.begin(), deepest_nodes.end());
    if (curr_nodes.empty()) return nullptr;
    while (curr_nodes.size() > 1) {
      set<TreeNode*> curr_parents;
      for (auto node : curr_nodes) {
        curr_parents.insert(parents[node]);
      }
      curr_nodes = curr_parents;
    }
    return *curr_nodes.begin();
  }
public:
  // Runtime: O(n)
  // Space: O(n)
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    if (root == nullptr) return nullptr;
    GetDeepValues(root, root, 0);
    vector<TreeNode*> deepest_nodes = deep_values.rbegin()->second;
    return GetLCA(deepest_nodes);
  }
};

int main(void) {
  return 0;
}