#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  unordered_map<TreeNode*, TreeNode*> parent;
  unordered_set<TreeNode*> visited;

  void AddParents(TreeNode* curr, TreeNode* from) {
    if (curr == nullptr) {
      return;
    }
    parent[curr] = from;
    AddParents(curr->left, curr);
    AddParents(curr->right, curr);
  }

  void FindNodes(TreeNode* curr, int distance, vector<int>& result) {
    if (curr == nullptr || distance < 0) {
      return;
    }
    visited.insert(curr);
    if (distance == 0) {
      result.push_back(curr->val);
      return;
    }
    const vector<TreeNode*> neighs = {curr->left, curr->right, parent[curr]};
    for (auto neigh : neighs) {
      if (!visited.count(neigh)) {
        FindNodes(neigh, distance - 1, result);
      }
    }
  }
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    AddParents(root, nullptr);
    vector<int> result;
    FindNodes(target, K, result);
    return result;
  }
};

int main(void) {
  return 0;
}