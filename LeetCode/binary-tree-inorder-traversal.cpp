#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insertLeftChildren(TreeNode* root, stack<TreeNode*>& st,
                        const unordered_map<TreeNode*, bool>& visited) {
  TreeNode* curr_node = root;
  while (curr_node->left != NULL && !visited.count(curr_node->left)) {
    st.push(curr_node->left);
    curr_node = curr_node->left;
  }
}

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> result;
  if (root == NULL) return result;
  stack<TreeNode*> st;
  unordered_map<TreeNode*, bool> visited;
  st.push(root);
  while (!st.empty()) {
    root = st.top();
    insertLeftChildren(root, st, visited);
    root = st.top();
    result.push_back(root->val);
    st.pop();
    if (root->right != NULL) {
      st.push(root->right);
    }
    visited[root] = true;
  }
  return result;
}

int main(void) {

  return 0;
}
