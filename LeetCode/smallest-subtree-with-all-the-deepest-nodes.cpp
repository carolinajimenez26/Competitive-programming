#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getCommonParent(vector<TreeNode*>& leafs,
                          unordered_map<TreeNode*, TreeNode*>& parents) {

      set<TreeNode*> result;
      set<TreeNode*> current_leafs(leafs.begin(), leafs.end());
      while (current_leafs.size() > 1) {
        for (auto leaf : current_leafs) {
          result.insert(parents[leaf]);
        }
        if (result.size() == 1) {
          auto it = result.begin();
          return *it;
        }
        current_leafs = result;
        result.clear();
      }
      return *current_leafs.begin();
    }

    bool isLeaf(TreeNode* node) {
      return node->left == NULL && node->right == NULL;
    }

    void getDepthsAndParents(TreeNode* node, int depth,
                             map<int, vector<TreeNode*>>& depths,
                             unordered_map<TreeNode*, TreeNode*>& parents,
                             TreeNode* parent) {

      if (node == NULL) return;
      depths[depth].push_back(node);
      parents[node] = parent;
      getDepthsAndParents(node->left, depth + 1, depths, parents, node);
      getDepthsAndParents(node->right, depth + 1, depths, parents, node);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
      if (isLeaf(root)) return root;
      map<int, vector<TreeNode*>> depths;
      unordered_map<TreeNode*, TreeNode*> parents; // child -> parent
      depths[0].push_back(root);
      parents[root] = NULL;
      getDepthsAndParents(root->left, 1, depths, parents, root);
      getDepthsAndParents(root->right, 1, depths, parents, root);
      // print(depths);
      // print(parents);
      auto rit = depths.rbegin();
      // get one of the maximum deepest nodes
      int deepest_val = rit->first;
      // dbg(deepest_val);
      
      return getCommonParent(depths[deepest_val], parents);
    }
};

int main(void) {
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);

  root->left->left = new TreeNode(6);
  Solution sol;
  TreeNode* subtree = sol.subtreeWithAllDeepest(root);
  // dbg(subtree->val);

  return 0;
}
