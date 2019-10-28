#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void InsertNodes(vector<int>& result, TreeNode* curr) {
    if (curr == nullptr) return;
    result.push_back(curr->val);
    InsertNodes(result, curr->left);
    InsertNodes(result, curr->right);
  }

  int kthSmallest(TreeNode* root, int k) {
    vector<int> nodes;
    InsertNodes(nodes, root);
    sort(nodes.begin(), nodes.end());
    return nodes[k - 1];
  }
};

int main(void) {
  return 0;
}