#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build2(vector<int>& p, int& id, int top) {
  TreeNode* root = NULL;
  if (id >= p.size() || p[id] >= top) {
    return root;
  }
  root = new TreeNode(p[id]);
  id++;
  root->left = build2(p, id, root->val);
  root->right = build2(p, id, top);
  return root;
}

TreeNode* bstFromPreorder2(vector<int>& preorder) {
  int id = 0;
  return build2(preorder, id, 200);
}

TreeNode* build(vector<int>& preorder, int start, int end) {
  if (start > end) {
    return NULL;
  }
  TreeNode* root = new TreeNode(preorder[start]);
  if ((end - start) == 0) {
    return root;
  }
  for (int i = start + 1; i <= end; i++) {
    if (preorder[i] > preorder[start]) {
      root->left = build(preorder, start + 1, i - 1);
      root->right = build(preorder, i, end);
      return root;
    }
  }
  root->left = build(preorder, start + 1, end);
  return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
  return build(preorder, 0, preorder.size() - 1);
}

int main(void) {
  vector<int> input = {8,5,1,7,6,9};//{4,10,7,9,11};
  TreeNode* root = bstFromPreorder(input);
  return 0;
}
