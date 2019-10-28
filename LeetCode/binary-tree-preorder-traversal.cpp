#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int> result;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode* n = st.top();
      st.pop();
      result.push_back(n->val);
      if (n->right != nullptr) {
        st.push(n->right);
      }
      if (n->left != nullptr) {
        st.push(n->left);
      }
    }
    return result;
  }
};

int main(void) {
  return 0;
}